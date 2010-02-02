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

#ifndef PA_BASICS_H
#define PA_BASICS_H

#include <iostream>
#include <SDL/SDL.h>

typedef Uint8 PaUint8;
typedef Uint16 PaChar;
typedef int PaInt;
typedef unsigned int PaUint;

namespace pa
{

struct Color {
    Color(PaUint8 r,PaUint8 g,PaUint8 b);
    operator SDL_Color();
    PaUint8 r,g,b;
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
    Image(PaChar,Color);
    PaChar ch;
    Color color;
};

struct Location {
    Location(PaInt x,PaInt y);
    PaInt x,y;
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
    huge = 256, //elephants
    gigantic = 1024 //
};

typedef PaUint Volume;

PaUint Random(PaUint,PaUint);
PaUint Dice(PaUint);

}//namespace pa


#endif // PA_BASICS_H