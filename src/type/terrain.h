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


#ifndef TERRAIN_H
#define TERRAIN_H

#include "pabasics.h"
#include "surface.h"
#include "../container/entitycontainer.h"


class Tree;

class Terrain : virtual public PaObject, public EntityContainer
{
public:
	Terrain(Location&&);
	Terrain(Terrain&&);
	Terrain& operator=(Terrain&& );
	Image  Get_Image() const;
	Location Get_Location() const;
	static Size Get_Volume();
	Color Get_Surface_Color() const;
	String Get_Description() const;
	Image Get_Next_Display_Image();

	bool Has_Wall();

	Tree* Get_Tree();
	bool Chop_Tree();
private:
	Location location;
	EntityContainer::iterator entities_display_it;
};

#endif // TERRAIN_H
