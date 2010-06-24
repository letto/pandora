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


#ifndef PABASICS_H
#define PABASICS_H

#include "../enum/color.h"

typedef uint16_t Char;
typedef int16_t int_enum_t;

struct Void {
};

class Int_t {
	int16_t value;
public:
	Int_t(const int16_t a):value{a} {}
	operator int16_t() const { return value;}
};

struct Image {
    Image(Char,Color);
    Char ch;
    Color color;
};

struct Location {
    Location(int16_t x,int16_t y):x{x},y{y} {}
    operator std::string () const;
    int16_t x,y;
};


int_fast32_t Random(const int_fast32_t, const int_fast32_t);
int_fast32_t Dice(const int_fast32_t);


void Exit(const std::string&);


#endif // PABASICS_H
