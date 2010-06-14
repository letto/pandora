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


#ifndef PA_BASICS_H
#define PA_BASICS_H

#include <SDL/SDL.h>
#include <string>
#include <boost/lexical_cast.hpp>

typedef uint16_t Char;

struct Color
{
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
    gray,
    olive,
    dark_blue,
    dark_cyan,
    dark_green,
    bright_green,
    soil_green;
    
    Color(uint8_t r,uint8_t g,uint8_t b):r{r},g{g},b{b}{}
    operator SDL_Color();
    uint8_t r,g,b;
};

struct Image {
    Image(Char,Color);
    Char ch;
    Color color;
};

struct Location {
    Location(int16_t x,int16_t y):x{x},y{y}{}
    operator std::string () const { return boost::lexical_cast<std::string>(x)+","+boost::lexical_cast<std::string>(y);}
    int16_t x,y;
};

enum class Direction {
    north,
    south,
    east,
    west,
    northeast,
    northwest,
    southwest,
    southeast
};

enum class Size : int16_t {
    none = 0,
    tiny = 1, //insects
    small = 16, //cats
    medium = 64, //dogs
    large = 128, //humans
    tree = 132,
    huge = 256, //elephants
    gigantic = 1024 //
};

typedef int16_t Volume;

int_fast32_t Random(const int_fast32_t, const int_fast32_t);
int_fast32_t Dice(const int_fast32_t);


void Exit(const std::string&);
bool operator>(Size,Size);

#endif // PA_BASICS_H
