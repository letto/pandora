/*
Copyright (C) 2010  Marius Stoica

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "interface.h"

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "wall.h"
#include "race/race.h"


using boost::lexical_cast;

extern World map;

Interface::Interface():
display_counter(0),cursor(0,0),
action_succes(false),action_type(Action::none),
cursor_mode(Cursor::following)
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
	pa::Exit("SDL_Init failed");
    SDL_WM_SetCaption(" Pandora ",NULL);
    
    video_Flags = SDL_OPENGL;
    video_Flags |= SDL_GL_DOUBLEBUFFER ;
    video_Flags |= SDL_HWPALETTE;
    video_Flags |= SDL_RESIZABLE;
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    screen = SDL_SetVideoMode( 1000, 800, 32, video_Flags ); 
    if(!screen)
	pa::Exit("SDL_SetVideoMode failed");

    const SDL_VideoInfo * videoInfo = SDL_GetVideoInfo( );
    if(!videoInfo)
	pa::Exit("SDL_GetVideoInfo failed");
    if ( videoInfo->hw_available )
	video_Flags |= SDL_HWSURFACE;
    else
	video_Flags |= SDL_SWSURFACE;
    if ( videoInfo->blit_hw )
	video_Flags |= SDL_HWACCEL;

    SDL_SetEventFilter(Event_Filter);
    
    
    player = Add_Player(Location(17,11),new Human());
    Add_Player(Location(26,19),new Elf());
    Add_Player(Location(27,18),new Human());
    Add_Player(Location(27,19),new Orc());
    Add_Player(Location(13,11),new Human());
    Add_Player(Location(13,11),new Orc());
    Add_Player(Location(7,11),new Human());
    Add_Player(Location(7,11),new Elf());
    
    Add_Player(Location(7,10),new Human());
    Add_Player(Location(7,13),new Human());
    Add_Player(Location(6,11),new Elf());
    
    Add_Player(Location(9,12),new Wall());
    
    player_id = player->Get_ID();
    cursor = player->Get_Location();
    
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
	
	engine.Run();
	
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
    rec.h = 5 * Terminal::Get_Glyph_Height();
    actions.Resize(rec);
    
    rec.y = actions.Get_Height();
    rec.h = Terminal::Get_Glyph_Height();
    rec.x = 0;
    rec.w = screen->w;
    info.Resize(rec);
    
    rec.y = rec.y + info.Get_Height();
    rec.h = screen->h - rec.y;
    rec.w = 15*Terminal::Get_Glyph_Width();
    rec.x = screen->w - rec.w;
    events.Resize(rec);
    
    rec.y = actions.Get_Height() + info.Get_Height();
    rec.h = screen->h - rec.y;
    rec.x = 0;
    rec.w = screen->w - events.Get_Width();
    display.Resize(rec);
    cursor = player->Get_Location();
}

void Interface::Draw_Display()
{
    switch(cursor_mode) {
	case Cursor::centered:
	    cursor = player->Get_Location();
	    break;
	case Cursor::following:
	    if(player->Get_Location().x - cursor.x > display.Get_Max_X()/2 - 4) cursor.x++;
	    if(player->Get_Location().y - cursor.y > display.Get_Max_Y()/2 - 2) cursor.y++;
	    if(cursor.x - player->Get_Location().x > display.Get_Max_X()/2 - 4) cursor.x--;
	    if(cursor.y - player->Get_Location().y > display.Get_Max_Y()/2 - 2) cursor.y--;
	    break;    
    }
    
    display_counter++;
    int pos_x = cursor.x - display.Get_Max_X()/2;
    int pos_y = cursor.y - display.Get_Max_Y()/2;
    Image img('?',pa::red);
    Color col(0,0,0);
    for(int cy = 0; cy <= display.Get_Max_Y();cy++) {
	for(int cx = 0; cx <= display.Get_Max_X(); cx++) {
	    if (cx+pos_x >= engine.Get_Map_Max_X()||
		cy+pos_y >= engine.Get_Map_Max_Y()||
		cx+ pos_x < 0 || cy+pos_y < 0) {
		img = Image('#',Color(35,35,35));
		col = Color(0,0,0);
	    } else {
		img = map(cx+pos_x ,cy+pos_y).Get_Next_Display_Image();
		col = map(cx+pos_x ,cy+pos_y).Get_Surface_Color();
	    }
	    display.Print_Char(img.ch, cx, cy, img.color, col);
	}
    }
}

void Interface::Draw_Info()
{
    Location loc = player->Get_Location();
    std::string ss;// = " " ;
    ss += "\nID: " + lexical_cast<std::string>(player_id) ;
    ss += " Disp Count " + lexical_cast<std::string>(display_counter);
    ss += " Loc " + lexical_cast<std::string>(loc.x) + "," + lexical_cast<std::string>(loc.y);
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
    EntityContainer* terrain = player->holder;
    Entity* ent = terrain->Get_First_Entity_Except(player);

    if (ent == NULL) {
	//ss += terrain->Get_Descripton();
    } else {
	ss += "You see ";
	while(ent != NULL) {
	    ss += ent->Get_Description();
	    Entity* ent_next = ent->Get_Next_Entity_Except(player);
	    if(ent_next != NULL) {
		Entity* ent_next_next = ent_next->Get_Next_Entity_Except(player);
		if(ent_next_next == NULL){
		    ss += " and ";
		} else {
		    ss += ", ";
		}
	    }
	    ent = ent_next;
	}
    }
    if(ss != "\n") {
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
	case SDLK_c:
	    if(player->Cut_Tree()) {
		actions.Print("\nYou cut a tree.");
	    } else {
		actions.Print("\nNo tree to cut.");
	    }
	    break;
	case SDLK_QUOTE:
	    if(player->Take_Entity(player->holder->Get_First_Entity_Except(player))) {
		actions.Print("\nYou take "+ player->holding->Get_Description());
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
		actions.Print("\nYou dropped "+ player->holder->Get_First_Entity()->Get_Description());
	    }
	    break;
	case SDLK_KP4:
	case SDLK_LEFT:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::west);
	    break;
	case SDLK_KP6:
	case SDLK_RIGHT:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::east);
	    break;
	case SDLK_KP8:
	case SDLK_UP:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::north);
	    break;
	case SDLK_KP2:
	case SDLK_DOWN:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::south);
	    break;
	case SDLK_KP9:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::northeast);
	    break;
	case SDLK_KP7:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::northwest);
	    break;
	case SDLK_KP3:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::southeast);
	    break;
	case SDLK_KP1:
	    action_type = Action::move;
	    action_succes = player->Go_Direction(pa::southwest);
	    break;
	default:
	    action_type = Action::none;
    }
}
