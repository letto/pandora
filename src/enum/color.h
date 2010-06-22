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

#ifndef COLOR_H
#define COLOR_H

#include <unordered_map>
#include <SDL/SDL_video.h>
#include "../type/pastring.h"

class Color
{
public:
static const Color
    black,
    white,
    red,
    green,
    blue,
    yellow,
    cyan,
    orange,
    tan,
    brown,
    gold,
    silver,
    olive,
    gray,
    dark_gray,
    dark_blue,
    dark_cyan,
    dark_green,
    bright_green,
    soil_green;
	
	operator SDL_Color() const;
	operator std::string() const;
	friend std::string operator+(const std::string&,const Color);
	friend std::string operator+(const Color,const std::string&);
    private:
	struct TColor {
	    TColor(uint8_t r,uint8_t g,uint8_t b);
	    uint8_t r,g,b;
	    operator int32_t() const;
	};
	Color(const char*, TColor);
	TColor value;
	static std::unordered_map<uint32_t, String> colormap;
};

#endif // COLOR_H

