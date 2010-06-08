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

#include <vector>
#include <typeinfo>

#include "surface.h"
#include "entitycontainer.h"

using pa::Image;
using pa::Color;
using pa::Location;

class Tree;

class Terrain : public EntityContainer,virtual public PaObject
{
public:
	Terrain(Location&&);
	Terrain(Terrain&&);
	Terrain& operator=(Terrain&& );
	Image  Get_Image() const;
	Location Get_Location() const;
	static Volume Get_Volume();
	Color Get_Surface_Color() const;
	std::string Get_Description() const;

	bool Has_Wall();

	Tree* Get_Tree();
	bool Chop_Tree();
private:
	static const Volume volume = Volume(350);
	Location location;
};

#endif // TERRAIN_H
