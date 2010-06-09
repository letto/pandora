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


#include "terrain.h"
#include "tree.h"
#include "wall.h"
#include <typeinfo>

Surface surface_grass;

Terrain::Terrain(Location&& location):
	EntityContainer(volume),
	location(location)
{}

Terrain::Terrain(Terrain&& t):
EntityContainer(volume),
location(t.location)
{
}

Terrain& Terrain::operator=(Terrain&& t)
{
    return t;
}

Location Terrain::Get_Location() const {
    return location;
}

Image Terrain::Get_Image() const {
    return surface_grass.Get_Image();
}

std::string Terrain::Get_Description() const
{
    std::string desc;
    if(Is_Empty()) {
	desc = "an empty patch of land";
    } else {
	desc = "a patch of land";
    }
    desc += " with " + surface_grass.Get_Description();
    return desc;
}

Tree* Terrain::Get_Tree()
{
    for(auto tree = begin(); tree != end();++tree) {
	if(typeid(**tree)==typeid(Tree)) {
	    return static_cast<Tree*>(*tree);
	}
    }
    return NULL;
}

bool Terrain::Chop_Tree()
{
    Tree* tree  = Get_Tree();
    if (!tree) {
	return false;
    }
    tree->Chop();
    return true;
}

bool Terrain::Has_Wall()
{
    for (auto ent = begin();ent != end();++ent) {
	if(typeid(**ent) == typeid(Wall)) {
	    return true;
	}
    }
    return false;
}

Color Terrain::Get_Surface_Color() const {
    return surface_grass.Get_Color();
}

Volume Terrain::Get_Volume() {
    return volume;
}
