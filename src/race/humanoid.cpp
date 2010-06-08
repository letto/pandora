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


#include "humanoid.h"
#include "../woodlog.h"

extern World map;

Size Humanoid::Get_Size() const {
    return Size::large;
}

Size Humanoid::Get_Max_Holding_Size() const {
    return Size::large;
}

bool Humanoid::Chop_Tree() const {
    // TODO: warn if holder is not terrain
    return static_cast<Terrain*>(holder)->Chop_Tree();
}

bool Humanoid::Build_Wall()
{
    if(holding == NULL ||
       typeid(*holding) != typeid(WoodLog)||
       !map(holder->Get_Location().x+1,holder->Get_Location().y).Is_Empty()) {
	return false;
    } else {
	map(holder->Get_Location().x+1,holder->Get_Location().y).Add_Entity(new Wall);
	delete holding;
	holding = NULL;
	return true;
    }
}

