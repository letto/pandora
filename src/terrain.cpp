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
{
}

Location Terrain::Get_Location() const {
    return location;
}

Image Terrain::Get_Image() {
    if(surface != NULL) {
	return surface->Get_Image();
    } else {
	return surface_none.Get_Image();
    }
}

Color Terrain::Get_Surface_Color() {
    return surface->Get_Color();
}

Volume Terrain::Get_Volume() {
    return volume;
}
