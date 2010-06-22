/*
    Copyright (C)  2010  Marius Stoica

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../patype.h"
#include "interface.h"

#include "../wall.h"
#include "../type/humanoid.h"
#include "cursor.h"

using boost::lexical_cast;

extern World map;
Interface* Interface::interface_instance = NULL;

Interface* Interface::Get_Interface() {
    if (interface_instance == NULL) {
	interface_instance = new Interface;
    }
    return interface_instance;
}

Interface::Interface():
	display_counter{0},
	action_succes{false},
	mode{ Mode::online},
	action_type{ Action::none},
	follow_mode{ FollowMode::following},
	cursor_loc{0,0},
	cursor{new Cursor}
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
	Exit("SDL_Init failed");
    SDL_WM_SetCaption(" Pandora ",NULL);
    Terminal::Set_Font("/usr/share/fonts/dejavu/DejaVuSansMono.ttf",32);
    
    video_Flags = SDL_OPENGL;
    video_Flags |= SDL_GL_DOUBLEBUFFER ;
    video_Flags |= SDL_HWPALETTE;
    video_Flags |= SDL_RESIZABLE;
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    screen = SDL_SetVideoMode( 1000, 800, 32, video_Flags ); 
    if(!screen) {
	Exit("SDL_SetVideoMode failed");
    }

    const SDL_VideoInfo * videoInfo = SDL_GetVideoInfo( );
    if(!videoInfo) {
	Exit("SDL_GetVideoInfo failed");
    }
    if ( videoInfo->hw_available ) {
	video_Flags |= SDL_HWSURFACE;
    } else {
	video_Flags |= SDL_SWSURFACE;
    }
    if ( videoInfo->blit_hw ) {
	video_Flags |= SDL_HWACCEL;
    }
    SDL_SetEventFilter(Event_Filter);
    
    
    player = Add_Player( Location{17,11}, new Humanoid{Race::human});
    current_ent = player;
    Add_Player( Location{26,19}, new Humanoid{Race::elf});
    Add_Player( Location{27,18}, new Humanoid{Race::human});
    Add_Player( Location{27,19}, new Humanoid{Race::orc});
    
    Add_Player( Location{16,14}, new Humanoid{Race::dwarf});
    Add_Player( Location{18,12}, new Humanoid{Race::dwarf});
    Add_Player( Location{22,13}, new Humanoid{Race::dwarf});
    Add_Player( Location{13,14}, new Humanoid{Race::dwarf});
    
    Add_Player( Location{13,11}, new Humanoid{Race::human});
    Add_Player( Location{13,11}, new Humanoid{Race::orc});
    Add_Player( Location{ 7,11}, new Humanoid{Race::human});
    Add_Player( Location{ 7,11}, new Humanoid{Race::elf});
    Add_Player( Location{14,13}, new Humanoid{Race::high_elf});
    Add_Player( Location{15,17}, new Humanoid{Race::half_elf});
    
    Add_Player( Location{ 7,10}, new Humanoid{Race::human});
    Add_Player( Location{ 7,13}, new Humanoid{Race::human});
    Add_Player( Location{ 6,11}, new Humanoid{Race::elf});
    
    Add_Player( Location{ 9,12}, new Wall);

    cursor_loc = current_ent->_Location();

    Resize();
}

Interface::~Interface()
{
    SDL_Quit();
}

void Interface::Run()
{
    Uint16 i = 32 ;
    SDL_Color change = {25,25,25};
    while(i < 61500 ) {
	i++;
	if(i >= 1200) i=32;
	
	if(mode == Mode::online) {
	    engine.Run();
	}
	
	Draw_Display();
	Draw_Actions();
	
	change.r += 28;change.g += 35;change.b+= 17;

	Draw_Info();
	
	//events.Print_Char('A'+(i%28),SDL_Black,change);
	//actions.Print_Char(9472+i-33,SDL_Black,change);
	//actions.Print_Char(8704+i-33,SDL_Black,change);

	SDL_Event event;
	if(SDL_PollEvent(&event)) {
	    Event_Handler(event);
	}
	display.Blit();
	info.Blit();
	events.Blit();
	actions.Blit();

	SDL_Delay( 150 );
	SDL_GL_SwapBuffers( );
    }
}

Humanoid* Interface::Add_Player(const Location& loc, Entity* entity)
{
    return static_cast<Humanoid*>(engine.Add_Entity(loc,entity));
}

void Interface::Resize()
{
    SDL_Rect rec;
    rec.x = rec.y = 0;
    rec.w = screen->w;
    rec.h = 5 * Terminal::_Glyph_Height();
    actions.Resize(rec);
    
    rec.y = actions._Height();
    rec.h = Terminal::_Glyph_Height();
    rec.x = 0;
    rec.w = screen->w;
    info.Resize(rec);
    
    rec.y = rec.y + info._Height();
    rec.h = screen->h - rec.y;
    rec.w = 15*Terminal::_Glyph_Width();
    rec.x = screen->w - rec.w;
    events.Resize(rec);
    
    rec.y = actions._Height() + info._Height();
    rec.h = screen->h - rec.y;
    rec.x = 0;
    rec.w = screen->w - events._Width();
    display.Resize(rec);

    cursor_loc = current_ent->_Location();
}

void Interface::Draw_Display()
{
    switch(follow_mode) {
	case FollowMode::centered:
	    cursor_loc = current_ent->_Location();
	    break;
	case FollowMode::following:
	    if( current_ent->_Location().x - cursor_loc.x > display._Max_X()/2 - 4 ) {
		cursor_loc.x++;
	    }
	    if( current_ent->_Location().y - cursor_loc.y > display._Max_Y()/2 - 2 ) {
		cursor_loc.y++;
	    }
	    if(cursor_loc.x - current_ent->_Location().x > display._Max_X()/2 - 4) {
		cursor_loc.x--;
	    }
	    if(cursor_loc.y - current_ent->_Location().y > display._Max_Y()/2 - 2) {
		cursor_loc.y--;
	    }
	    break;
    }
    
    display_counter++;
    int pos_x = cursor_loc.x - display._Max_X()/2;
    int pos_y = cursor_loc.y - display._Max_Y()/2;
    Image img{ '?', Color::red};
    Color col = Color::black;
    for(int cy = 0; cy <= display._Max_Y();cy++) {
	for(int cx = 0; cx <= display._Max_X(); cx++) {
	    if(	cx+pos_x >= engine._Map_Max_X()||
		cy+pos_y >= engine._Map_Max_Y()||
		cx+ pos_x < 0 || cy+pos_y < 0) {
		    img = Image{ '#', Color::dark_gray};
		    col = Color::black;
	    } else {
		    img = map(cx+pos_x ,cy+pos_y)._Next_Display_Image();
		    col = map(cx+pos_x ,cy+pos_y)._Surface_Color();
	    }
	    display.Print_Char(img.ch, cx, cy, img.color, col);
	}
    }
}

void Interface::Draw_Info()
{
    std::string ss;
    ss += "\nID: " + (std::string)player->id;
    ss += " Disp Count " + lexical_cast<std::string>(display_counter);
    ss += " Loc " + (std::string)(current_ent->_Location());
    info.Print(ss);
}

void Interface::Draw_Actions()
{
    if(action_type == Action::none) {
	return;
    }
    action_type = Action::none;
    if(!action_succes) {
	actions.Print("\nYou are blocked.");
	return;
    }

    std::string ss = "\n";

    auto end = current_ent->_Holder()->end();
    auto ent = current_ent->_Holder()->begin();
    if( *ent == current_ent) {
	++ent;
    }
    if( ent ) {
	ss += "You see ";
	for(; ent; ++ent) {
	    if (*ent == current_ent) {
		++ent;
	    }
	    if( !ent ) {
		break;
	    }
	    ss += Get_Article(ent->_Description()) + ent->_Description();
	    auto ent_next = ent;
	    ++ent_next;
	    if( *ent_next == current_ent) {
		++ent_next;
	    }
	    auto ent_next_next = ent_next;
	    if( ent_next_next ) {
		++ent_next_next;
	    }
	    if( *ent_next_next == current_ent) {
		++ent_next_next;
	    }
	    if( ent_next ) {
		if( !ent_next_next ) {
		    ss += " and ";
		} else {
		    ss += ", ";
		}
	    }
	}
	ss += ".";
	actions.Print(ss);
    }
}

int Interface::Event_Filter(const SDL_Event* const event)
{
    switch(event->type) {
	case SDL_QUIT:
	case SDL_KEYDOWN:
	case SDL_VIDEORESIZE:
	case SDL_VIDEOEXPOSE:
	    return 1;
	    break;
	default:
	    return 0;
    }
}

void Interface::Event_Handler(const SDL_Event& event)
{
    switch(event.type) {
	case SDL_VIDEORESIZE:
	    glClear(GL_COLOR_BUFFER_BIT);
	    screen = SDL_SetVideoMode(event.resize.w,event.resize.h,32,video_Flags);
	    Resize();
	    break;
	case SDL_VIDEOEXPOSE:
	    glClear(GL_COLOR_BUFFER_BIT);
	    display.Refresh();
	    info.Refresh();
	    events.Refresh();
	    actions.Refresh();
	    break;
	case SDL_KEYDOWN:
	    Keyboard_Handler(event.key.keysym);
	    break;
	case SDL_QUIT:
	    SDL_Quit();
	    exit(1);
	    break;
    }
}

void Interface::Keyboard_Handler(const SDL_keysym& key)
{
    switch(key.sym) {
	case SDLK_ESCAPE:
	    switch(mode) {
		case Mode::online:
		    mode = Mode::cursor;
		    current_ent = cursor;
		    map(player->_Location()).Insert_Entity(cursor);
		    break;
		case Mode::cursor:
		    mode = Mode::online;
		    current_ent = player;
		    map(cursor->_Location()).Remove_Entity(cursor);
		    break;
	    }
	    cursor_loc = current_ent->_Location();
	    break;
	case SDLK_c:
	    if(player->Chop_Tree()) {
		actions.Print("\nYou cut a tree.");
	    } else {
		actions.Print("\nNo tree to cut.");
	    }
	    break;
	case SDLK_QUOTE:
	    if(player->Take_Entity(player->_Holder()->_First_Entity_Except(player))) {
		actions.Print("\nYou take "+ player->holding->_Description());
	    } else {
		actions.Print("\nNo item to take.");
	    }
	    break;
	case SDLK_b:
	    if(player->Build_Wall()) {
		actions.Print("\nYou build a wall.");
	    } else {
		actions.Print("\nYou fail to build a wall.");
	    }
	    break;
	case SDLK_d:
	    if(player->Drop_Entity()) {
		actions.Print("\nYou dropped "+ player->_Holder()->begin()->_Description());
	    }
	    break;
	case SDLK_KP4:
	case SDLK_LEFT:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::west);
	    break;
	case SDLK_KP6:
	case SDLK_RIGHT:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::east);
	    break;
	case SDLK_KP8:
	case SDLK_UP:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::north);
	    break;
	case SDLK_KP2:
	case SDLK_DOWN:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::south);
	    break;
	case SDLK_KP9:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::northeast);
	    break;
	case SDLK_KP7:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::northwest);
	    break;
	case SDLK_KP3:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::southeast);
	    break;
	case SDLK_KP1:
	    action_type = Action::move;
	    action_succes = current_ent->Go_Direction(Direction::southwest);
	    break;
	default:
	    action_type = Action::none;
    }
}
