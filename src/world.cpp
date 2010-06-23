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

#include "patype.h"
#include "tree.h"


World::World(int16_t max_x, int16_t max_y):
	max_x{max_x},
	max_y{max_y}
{
    map.reserve(max_x*max_y);
    
    for(int cx = 0; cx< max_x;cx++) {
	for(int cy = 0; cy < max_y;cy++) {
	    map.push_back(std::move(Terrain{Location{cx,cy}}));
	}
    }
}

Terrain& World::operator()(const int16_t x ,const int16_t y) {
    return map[x*max_y + y];
}

Terrain& World::operator()(const Location loc) {
    return operator()(loc.x ,loc.y);
}

void World::Generate()
{
    for(int cx = 0; cx < max_x - 4 ; cx+=5) {
	for(int cy = 0;cy < max_y - 3; cy+=4) {
	    for(int i = 0; i < 4 ; i++ ) {
		int x = cx + Random(0,4);
		int y = cy + Random(0,3);
		if(operator()(x,y).Is_Empty())
		    operator()(x,y).Add_Entity(new Tree);
	    }
	}
    }
}