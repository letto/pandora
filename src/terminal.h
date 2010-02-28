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

#ifndef TERMINAL_H
#define TERMINAL_H

#include <map>
#include <unordered_map>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>



static const SDL_Color SDL_White = {255,255,255};
static const SDL_Color SDL_Black = {0,0,0};


class TermChar {
public:
	TermChar();
	TermChar(Uint16 ch,SDL_Color fg ,SDL_Color bg);
	Uint16 ch;
	SDL_Color bg;
	SDL_Color fg;
	bool changed;
	friend bool operator==(const TermChar&,const TermChar&);
	friend bool operator!=(const TermChar&,const TermChar&);
};

struct TermGlyph {
    GLuint texture;
    int min_x;
};

class Terminal
{
public:
	static void Set_Font(const std::string& font_path ,const int& size);
	Terminal();
	
	void Print_Char(const Uint16&,const SDL_Color& fg = SDL_White ,const SDL_Color& bg = SDL_Black);
	void Print_Char(const Uint16&,const int& cpos_x ,const int& cpos_y ,const SDL_Color& fg ,const SDL_Color& bg);
	void New_Line();
	void Print(const std::string& ,const SDL_Color& = SDL_White ,const SDL_Color& bg = SDL_Black);
	
	void Blit();
	void Refresh();
	void Resize(const SDL_Rect&);
	
	int Get_Max_X();
	int Get_Max_Y();
	
	int Get_Width();
	int Get_Height();
	static int Get_Glyph_Width();
	static int Get_Glyph_Height();
private:
	static TTF_Font* font;
	static int glyph_w,glyph_h;
	static int glyph_rect_w,glyph_rect_h;
	static std::unordered_map< Uint16, TermGlyph> charmap;
	static TermGlyph Get_Glyph(const Uint16&);
	
	static SDL_Surface *screen; //The app screen
	SDL_Rect term_rect;     // The terminal screen
	
	int cursor_x,cursor_y;    //cursor
	int cursor_max_x,cursor_max_y;
	//int buffer_start;
	static const int buffer_max = 300 ; 
	TermChar buffer[100][buffer_max];
	
	
	//Debug functions
	//void Dump_Charmap();
};
                                               
#endif // TERMINAL_H
