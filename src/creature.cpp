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

#include "creature.h"

#include "terrain.h"
#include "pa_engine.h"

extern Map map;
extern PaInt map_max_x;
extern PaInt map_max_y;

// Creature::Creature()
// {
//     //std::cout << "ID " << id <<" Adress " << this << "\n";
// }

bool Creature::Go_Direction(Direction direction)
{
    Location loc = Get_Location();
    Location dest = loc;
    switch(direction) {
	case pa::northeast:
	    dest.x++;    
	case pa::north:
	    dest.y++;
	    break;
	case pa::southeast:
	    dest.x++;
	case pa::south:
	    dest.y--;
	    break;
	case pa::southwest:
	    dest.y--;
	case pa::west:
	    dest.x--;
	    break;
	case pa::northwest:
	    dest.y++;
	    dest.x--;
	    break;
	case pa::east:
	    dest.x++;
	    break;
    }
    if(dest.x < 0 || dest.y < 0 || dest.x >= map_max_x || dest.y >= map_max_y) {
	return false;
    }
    
    if(map[dest.x][dest.y].Has_Space(this)){
	map[loc.x][loc.y].Remove_Entity(this);
	map[dest.x][dest.y].Insert_Entity(this);
	return true;
    } else {
	return false;
    }
}

