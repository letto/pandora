/*
    Copyright (C) 2010 Marius Stoica

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

#include "world.h"


World::World(PaInt max_x, PaInt max_y):max_x(max_x),max_y(max_y)
{
    map.reserve(max_x*max_y);
    
    for(int cx = 0; cx< max_x;cx++) {
	for(int cy = 0; cy < max_y;cy++) {
	    map.push_back( Terrain(Location(cx,cy)));    
	}
    }
}

Terrain& World::operator()(const PaInt& x ,const PaInt& y) {
    return map[x*max_y + y];
}

Terrain& World::operator()(const pa::Location& loc) {
    return (*this)(loc.x ,loc.y);
}