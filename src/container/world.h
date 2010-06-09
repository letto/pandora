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
#include "../terrain.h"
#include <vector>

using pa::Random;

class World
{
public:
	Terrain& operator()(const int16_t, const int16_t);
	Terrain& operator()(const pa::Location);
	World(const int16_t max_x,const int16_t max_y);
	int16_t max_x,max_y;
	void Generate();
private:
	std::vector<Terrain> map;
};

#endif // WORLD_H
