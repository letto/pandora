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

#include "../patype.h"

extern World map;

Creature::Creature():
	holding(NULL)
{
}

bool Creature::Go_Direction(const Direction& direction)
{
    Location loc = Get_Location();
    Location dest = loc;
    switch(direction) {
	case Direction::northeast:
	    dest.x++;    
	case Direction::north:
	    dest.y++;
	    break;
	case Direction::southeast:
	    dest.x++;
	case Direction::south:
	    dest.y--;
	    break;
	case Direction::southwest:
	    dest.y--;
	case Direction::west:
	    dest.x--;
	    break;
	case Direction::northwest:
	    dest.y++;
	    dest.x--;
	    break;
	case Direction::east:
	    dest.x++;
	    break;
    }
    if(dest.x < 0 || dest.y < 0 || dest.x >= map.max_x || dest.y >= map.max_y) {
	return false;
    }
    
    if(map(dest).Has_Space_For(this)){
	map(loc).Remove_Entity(this);
	map(dest).Insert_Entity(this);
	return true;
    } else {
	return false;
    }
}

bool Creature::Take_Entity(Entity* item) 
{
    if(item == NULL) {
	// TODO: Warning
	return false;
    }
    if(holding != NULL) {
	return false;
    }
    if(item->Get_Size() > Get_Max_Holding_Size()) {
	return false;
    }

    if(!holder->Remove_Entity(item)) {
	return false;
    } else {
	holding = item;
	//item->holder = this;
	return true;
    }
}

bool Creature::Drop_Entity()
{
    if(holding && holder->Add_Entity(holding)) {
	holding = NULL;
	return true;
    } else {
	return false;
    }
}
