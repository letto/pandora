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

#include "terminal.h"
#include <iostream>
#include <string>

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
#define		SDL_SURFACE_MASK	0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff
#else
#define		SDL_SURFACE_MASK	0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000
#endif


TTF_Font* Terminal::font = NULL;
std::unordered_map< Uint16, TermGlyph> Terminal::charmap;
int Terminal::glyph_w = 0;
int Terminal::glyph_h = 0;
int Terminal::glyph_rect_w = 0;
int Terminal::glyph_rect_h = 0;
SDL_Surface* Terminal::screen = NULL;

void Terminal::Set_Font(const char* font_path ,const int& size)
{
    if((TTF_Init() !=0 ) && !TTF_WasInit()) {
	std::cerr << " SDL_ttf initialization failed! " << std::endl;
	exit(1);
    }
    if(font != NULL) {
	std::cerr << "Trying to reset font" << std::endl;
	exit(1);
    }
    font = TTF_OpenFont(font_path ,size);
    if(!font) {
	std::cerr << "Error loading font!" << std::endl;
	exit(1);
    }
    if(!TTF_FontFaceIsFixedWidth(font)) {
	std::cerr << "The font is not of fixed width!" << std::endl;
	exit(1);
    }
    
    TTF_GlyphMetrics(font, 9587, 0, 0,0,0, &glyph_w);
    glyph_h = TTF_FontAscent(font) - TTF_FontDescent(font);
    //std::cout << "glyph size wxh: " << glyph_w << " " << glyph_h << std::endl;
}

Terminal::Terminal():
	cursor_x(0),cursor_max_x(0),
	cursor_y(0),cursor_max_y(0)
{
}

int Terminal::Get_Max_X() {
    return cursor_max_x;
}

int Terminal::Get_Max_Y() {
    return cursor_max_y;
}

int Terminal::Get_Glyph_Width() {
    return glyph_w;
}

int Terminal::Get_Glyph_Height() {
    return glyph_h;
}

int Terminal::Get_Width() {
    return term_rect.w;
}

int Terminal::Get_Height() {
    return term_rect.h;
}

void Terminal::Resize(const SDL_Rect& rec)
{
    screen = SDL_GetVideoSurface();
    if(!screen) {
	std::cerr << "SDL_GetVideoSurface failed" << std::endl;
	exit(1);
    }
    glViewport(0, 0, screen->w, screen->h);
    
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glDisable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    glClear(GL_COLOR_BUFFER_BIT);    
    //Required for background rendering
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    
    term_rect = rec;
    int last_max_y = cursor_max_y;
    cursor_max_x = term_rect.w/glyph_w - 1;
    cursor_max_y = term_rect.h/glyph_h - 1;

    term_rect.w = (cursor_max_x+1)*glyph_w;
    term_rect.h = (cursor_max_y+1)*glyph_h;
    //std::cout << "Terminal size: " << cursor_max_y+1 << " x"<< cursor_max_x+1 << std::endl;
    
    if (last_max_y < cursor_max_y) {
	int cy = 0;
	for(; cy <= last_max_y; cy++) {
	    for(int cx =0; cx <= cursor_max_x; cx++) {
		buffer[cx][cursor_max_y - cy] = buffer[cx][last_max_y - cy];
		buffer[cx][cursor_max_y - cy].changed = true;
	    }
	}
	cursor_y += cursor_max_y - cy +1;
	for(;cy <= cursor_max_y;cy++) {
	    for(int cx =0; cx <= cursor_max_x; cx++) {
		buffer[cx][cursor_max_y - cy] = TermChar();
	    }
	}
    } else if(last_max_y > cursor_max_y) {
	for(int cy = 0; cy <= cursor_max_y ;cy++) {
	    for(int cx =0; cx <= cursor_max_x; cx++) {
		if (cursor_max_y > last_max_y - cursor_y) {
		    if(cy > last_max_y - cursor_y) {
			buffer[cx][cursor_max_y - cy] = TermChar();
		    } else {
			buffer[cx][cursor_max_y - cy] = buffer[cx][last_max_y - cy];
			buffer[cx][cursor_max_y - cy].changed = true;
		    }
		}
	    }
	}
	if (cursor_max_y > last_max_y - cursor_y) {
	    cursor_y = cursor_max_y - (last_max_y - cursor_y);
	    cursor_y = cursor_y < 0?0:cursor_y;
	}
    }
    for(int cx = cursor_x; cx <= cursor_max_x; cx++) {
	buffer[cx][cursor_y] = TermChar();
    }
}

void Terminal::Print_Char(const Uint16& ch ,const int& cpos_x ,const int& cpos_y ,const SDL_Color& fg ,const SDL_Color& bg)
{ 
    if(buffer[cpos_x][cpos_y] != TermChar(ch,fg,bg)) {
	buffer[cpos_x][cpos_y] = TermChar(ch,fg,bg);
    }
}

void Terminal::Print_Char(const Uint16& ch,const SDL_Color& fg ,const SDL_Color& bg)
{
    Print_Char(ch,cursor_x,cursor_y,fg,bg);
    if(cursor_x >= cursor_max_x) { //needs >= to handle resize
	New_Line();
    } else {
	cursor_x++;
    }
}

void Terminal::Print(const std::string& str ,const SDL_Color& fg ,const SDL_Color& bg)
{
    for(auto ch = str.begin(); ch< str.end();ch++) {
	if( *ch =='\n') {
	    New_Line();
	} else {
	    Print_Char(*ch,fg,bg);
	}
    }
}

void Terminal::New_Line()
{
    cursor_x = 0;
    if (cursor_y > 0) {
	cursor_y--;
    } else {
	for(int cy = cursor_max_y; cy > cursor_y;  cy--) {
	    for(int cx = 0; cx <= cursor_max_x; cx++) {
		buffer[cx][cy] = buffer[cx][cy-1];
		buffer[cx][cy].changed = true;
	    }
	}
	for(int cx = 0; cx <= cursor_max_x; cx++) {
	    buffer[cx][cursor_y] = TermChar();
	}
    }
}

void Terminal::Blit()
{
    int pix_x = 0;
    int pix_y = glyph_h*(cursor_max_y);

    for(int cy = cursor_max_y; cy >= 0;  cy--) {
	pix_x = 0;
	for(int cx = 0; cx <= cursor_max_x; cx++) {
	    if(buffer[cx][cy].changed) {
		buffer[cx][cy].changed = false;
		//std::cout << " Printing " << buffer[cx][cy].ch << std::endl;

		glViewport((GLint)term_rect.x, (GLint)term_rect.y, (GLsizei)term_rect.w, (GLsizei)term_rect.h );
		glMatrixMode (GL_PROJECTION);
		glPushMatrix ();
		glLoadIdentity ();
		glOrtho (0, (GLdouble)term_rect.w, 0, (GLdouble)term_rect.h, -1, 1);
// 		glMatrixMode(GL_MODELVIEW);
// 		glPushMatrix();
// 		glLoadIdentity();
		
		// Render background
		glDisable(GL_TEXTURE_2D);
		glColor3ub(buffer[cx][cy].bg.r,buffer[cx][cy].bg.g,buffer[cx][cy].bg.b);
		glBegin(GL_QUADS); 
		    glVertex2f(pix_x   , pix_y);
		    glVertex2f(pix_x + glyph_w, pix_y);
		    glVertex2f(pix_x + glyph_w, pix_y + glyph_h);
		    glVertex2f(pix_x, pix_y + glyph_h);
		glEnd();
		
		// Draw letter
		int min_x = Get_Glyph(buffer[cx][cy].ch).min_x;
		min_x = min_x > 0?0:min_x;
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, Get_Glyph(buffer[cx][cy].ch).texture);
		glColor3ub(buffer[cx][cy].fg.r,buffer[cx][cy].fg.g,buffer[cx][cy].fg.b);
		glBegin(GL_QUADS);
		    glTexCoord2f(0.0f, 1.0f); 
		    glVertex2f(pix_x + min_x , pix_y + glyph_h - glyph_rect_h);
		    glTexCoord2f(1.0f, 1.0f); 
		    glVertex2f(pix_x + min_x + glyph_rect_w, pix_y + glyph_h - glyph_rect_h);
		    glTexCoord2f(1.0f, 0.0f); 
		    glVertex2f(pix_x + min_x + glyph_rect_w, pix_y + glyph_h);
		    glTexCoord2f(0.0f, 0.0f); 
		    glVertex2f(pix_x + min_x, pix_y + glyph_h);
		glEnd();
		glFinish();
		
		
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();   
		//glMatrixMode(GL_MODELVIEW);
		//glPopMatrix();
		   
	    }
	    pix_x += glyph_w;
	}
	pix_y -= glyph_h;
    }
}

void Terminal::Refresh()
{
    for(int cy = cursor_max_y; cy >=0; cy--)
	for(int cx = 0; cx <= cursor_max_x; cx++)
	    buffer[cx][cy].changed = true;
}

TermGlyph Terminal::Get_Glyph(const Uint16& ch) 
{
    if(ch == '\0') {
	return Get_Glyph(' ');
    }
    if ( charmap.count(ch) == 0) {
	
	//if(!TTF_GlyphIsProvided(font,ch)) {
	//std::cout << "Warning: Trying to use unprovided glyph: " << ch <<std::endl;
	//}

	//
	Uint16 text[] = { ch,'\0'};
	SDL_Surface* initial = TTF_RenderUNICODE_Solid(font,text,SDL_White);
	if (glyph_rect_h == 0) {
	    int i = 2;
	    while(i < initial->w) i *= 2;
	    glyph_rect_w = i;
	    i = 2;
	    while( i < initial->h) i *= 2;
	    glyph_rect_h = i;
	}

	SDL_Surface * intermediary = SDL_CreateRGBSurface(0, glyph_rect_w, glyph_rect_h, 32, SDL_SURFACE_MASK);

	SDL_BlitSurface(initial, 0, intermediary, 0);

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, glyph_rect_w, glyph_rect_h, 0, GL_BGRA, 
		    GL_UNSIGNED_BYTE, intermediary->pixels );


	SDL_FreeSurface(initial);
	SDL_FreeSurface(intermediary);
	
	TermGlyph tmp;
	tmp.texture = texture;
	TTF_GlyphMetrics(font, ch, &tmp.min_x, 0, 0, 0, 0);
	charmap.insert(std::pair<Uint16,TermGlyph>( ch, tmp));

	//std::cout << "charmaping " << ch <<std::endl;
    } else {
	//std::cout << "Using mapped: " << ch <<std::endl;
    }
    
    return charmap[ch];
}


TermChar::TermChar()
{
    ch = '\0';
    fg.r =fg.g =fg.b = 255;
    bg.r =bg.g =bg.b = 0;
    changed = true;
}

TermChar::TermChar(Uint16 ch,SDL_Color fg ,SDL_Color bg):
	ch(ch),
	fg(fg),
	bg(bg),
	changed(true)
{
}

bool operator==(const TermChar& tb_a,const TermChar& tb_b) 
{
    if(tb_a.ch != tb_b.ch ) 
	return false;
    if((tb_a.fg.r != tb_b.fg.r )||
       (tb_a.fg.g != tb_b.fg.g )|| 
       (tb_a.fg.b != tb_b.fg.b )) {
	return false;
    }
    if((tb_a.bg.r != tb_b.bg.r )||
       (tb_a.bg.g != tb_b.bg.g )||
       (tb_a.bg.b != tb_b.bg.b )) {
	return false;
    }
    return true;
}

bool operator!=(const TermChar& tb_a,const TermChar& tb_b) {
    return !(tb_a == tb_b);
}
