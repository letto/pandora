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


#ifndef WORLD_H
#define WORLD_H

#include "type/pabasics.h"
#include "type/terrain.h"
#include <vector>

class World
{
public:
	static World* _World();
	static void Delete();
	Terrain& operator()(const int16_t, const int16_t);
	Terrain& operator()(const Location);
	Int_t max_x,max_y;
	void Generate();
private:
	World(const int16_t max_x,const int16_t max_y);
	World(const World&) = delete;
	World operator=(const World&) = delete;
	~World() = default;
	static World* instance;
	std::vector<Terrain> map;
};

class World_Ptr
{
public:
	World_Ptr():world{ World::_World()} {}
	Terrain& operator()(const int16_t a, const int16_t b) { return world->operator()(a,b);}
	Terrain& operator()(const Location loc) { return world->operator()(loc);}
	World* operator->() { return world;}
	World* operator*() { return world;}
private:
	World* world;
};

#endif // WORLD_H


