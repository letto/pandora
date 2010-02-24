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

#include "terrain.h"

Surface surface_none;
Surface surface_grass;

Terrain::Terrain(Location location):EntityContainer(volume),
surface(const_cast<Surface*>(&surface_grass)),
location(location)
{}

Location Terrain::Get_Location() const {
    return location;
}

Image Terrain::Get_Image() const
{
    if(surface != NULL) {
	return surface->Get_Image();
    } else {
	return surface_none.Get_Image();
    }
}

std::string Terrain::Get_Description() const
{
    std::string desc;
    if(Is_Empty()) {
	desc = "an empty patch of land";
    } else {
	desc = "a patch of land";
    }
    desc += " with " + surface->Get_Description();
    return desc;
}

Tree* Terrain::Get_Tree()
{
    Entity* tree = Get_First_Entity();
    while(tree != NULL) {
	if(typeid(*tree)==typeid(Tree)) {
	    return dynamic_cast<Tree*>(tree);
	}
	tree = tree->next;
    }
    return NULL;
}

bool Terrain::Cut_Tree()
{
    Tree* tree  = Get_Tree();
    if (!tree) {
	return false;
    }
    Remove_Entity(tree);
    delete tree;
    Put_Entity(new WoodLog);
    Put_Entity(new WoodLog);
    return true;
}


Color Terrain::Get_Surface_Color() const {
    return surface->Get_Color();
}

Volume Terrain::Get_Volume() {
    return volume;
}
