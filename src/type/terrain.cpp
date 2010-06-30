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
#include "../tree.h"
#include "../wall.h"

Surface surface_grass;

Terrain::Terrain(Location&& location):
	EntityContainer{Size::terrain},
	location{location},
	entities_display_it{NULL}
{
}

Terrain::Terrain(Terrain&& t):
	EntityContainer{Size::terrain},
	location{t.location},
	entities_display_it{t.entities_display_it}
{
}

Terrain& Terrain::operator=(Terrain&& t) {
    return t;
}

Location Terrain::_Location() const {
    return location;
}

Image Terrain::_Image() const {
    return surface_grass._Image();
}

String Terrain::_Description() const
{
    std::string desc;
    if(Is_Empty()) {
	desc = "an empty patch of land";
    } else {
	desc = "a patch of land";
    }
    desc += " with " + surface_grass._Description();
    return String(desc);
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

Color Terrain::_Surface_Color() const {
    return surface_grass._Color();
}

Size Terrain::_Volume() {
    return Size::terrain;
}

Image Terrain::_Next_Display_Image()
{
    if(Is_Empty()) {
	return _Image();
    }
    if( Has_Entity(*entities_display_it)) {
	if(entities_display_it) {
	    ++entities_display_it;
	}
	if( !entities_display_it ) {
	    entities_display_it = begin();
	}
    } else {
	entities_display_it = begin();
    }
    return entities_display_it->_Image();
}


