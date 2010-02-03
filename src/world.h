/*
    Copyright (C) 2010 Marius Stoica

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

#ifndef WORLD_H
#define WORLD_H
#include "terrain.h"

class World
{
public:
	Terrain& operator()(const PaInt&, const PaInt&);
	Terrain& operator()(const pa::Location&);
	World(PaInt max_x,PaInt max_y);
	PaInt max_x,max_y;
private:
	std::vector<Terrain> map;
};

#endif // WORLD_H
