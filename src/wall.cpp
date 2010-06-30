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


#include "wall.h"


Image Wall::_Image() const
{
    World_Ptr map;
    Location loc = holder->_Location();
    Color col = Color::brown;
    bool wall_up = map(loc.x,loc.y+1).Has_Wall();
    bool wall_down = map(loc.x,loc.y-1).Has_Wall();
    bool wall_right = map(loc.x+1,loc.y).Has_Wall();
    bool wall_left = map(loc.x-1,loc.y).Has_Wall();

    if(wall_up && wall_down && wall_left && wall_right)
	return Image{ 9532, col};
    if(wall_up && wall_down && wall_left)
	return Image{ 9508, col};
    if(wall_up && wall_down && wall_right)
	return Image{ 9500, col};
    if(wall_up && wall_left && wall_right)
	return Image{ 9524, col};
    if(wall_down && wall_left && wall_right)
	return Image{ 9516, col};
    if(wall_up && wall_down)
	return Image{ 9474, col};
    if(wall_up && wall_left)
	return Image{ 9496, col};
    if(wall_up && wall_right)
	return Image{ 9492, col};
    if(wall_left && wall_right)
	return Image{ 9472, col};
    if(wall_down && wall_left)
	return Image{ 9488, col};
    if(wall_down && wall_right)
	return Image{ 9484, col};
    if(wall_up)
	return Image{ 9589, col};
    if(wall_down)
	return Image{ 9591, col};
    if(wall_left)
	return Image{ 9588, col};
    if(wall_right)
	return Image{ 9590, col};

    return Image{ 10799, col};
}

String Wall::_Description() const {
    return String{"wall"};
}

Size Wall::_Size() const {
    return Terrain::_Volume();
}


