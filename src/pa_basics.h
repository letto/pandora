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

#include <iostream>
#include <SDL/SDL.h>

namespace pa
{

typedef uint16_t Char;

struct Color {
    Color(uint8_t r,uint8_t g,uint8_t b);
    operator SDL_Color();
    uint8_t r,g,b;
};

const Color white(255,255,255);
const Color black(0,0,0);
const Color red(255,0,0);
const Color green(0,192,0);
const Color blue(0,0,255);
const Color yellow(255,255,0);
const Color cyan(0,255,255);
const Color orange(255,165,0);
const Color brown(184,134,11);
const Color tan(210,180,140);
const Color gold(255,215,0);
const Color silver(192,192,192);
const Color gray(127,127,127);
const Color olive(75,128,75);
const Color dark_blue(0,0,139);
const Color dark_cyan(0,139,139);
const Color dark_green(0,80,0);
const Color bright_green(0,255,0);
const Color soil_green(0,15,0);

struct Image {
    Image(Char,Color);
    Char ch;
    Color color;
};

struct Location {
    Location(int16_t x,int16_t y):x(x),y(y){}
    int16_t x,y;
};

enum Direction {
    north, south, east, west, northeast, northwest, southwest, southeast
};

enum class Size {
    none = 0,
    tiny = 1, //insects
    small = 16, //cats
    medium = 64, //dogs
    large = 128, //humans
    tree = 132,
    huge = 256, //elephants
    gigantic = 1024 //
};

typedef uint16_t Volume;

int_fast32_t Random(const int_fast32_t, const int_fast32_t);
int_fast32_t Dice(const int_fast32_t);

void Exit(const std::string&);

}//namespace pa

bool operator>(pa::Size,pa::Size);

#include <boost/flyweight.hpp>
extern template class boost::flyweights::flyweight<std::string>;
typedef boost::flyweights::flyweight<std::string> String;
std::string operator+(std::string, String);

#endif // PA_BASICS_H