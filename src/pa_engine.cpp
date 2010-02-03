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

#include "pa_engine.h"

PaUint map_max_x = 931;
PaUint map_max_y = 863;
Map map;

PandoraEngine::PandoraEngine()
{
    map.reserve(map_max_x);
    for(int cx = 0; cx< map_max_x;cx++) {
	map.push_back( std::vector<Terrain>() );
	map[cx].reserve(map_max_y);
	for(int cy = 0; cy < map_max_y;cy++) {
	    map[cx].push_back(Terrain(Location(cx,cy)));
	}
    }
    
    for(PaUint cy = 0;cy < map_max_y - 3; cy+=4)
	for(PaUint cx = 0; cx < map_max_x - 4 ; cx+=5) {
	    for(int i = 0; i < 4 ; i++ ) {
		int x = cx + Random(0,4);
		int y = cy + Random(0,3);
		if(map[x][y].Is_Empty())
		    map[x][y].Put_Entity(new Tree);
	    }
	}
}

void PandoraEngine::Run()
{
    
}

PaInt PandoraEngine::Get_Map_Max_X(){
    return map_max_x;
}

PaInt PandoraEngine::Get_Map_Max_Y(){
    return map_max_y;
}

Entity* PandoraEngine::Add_Entity(const Location& loc ,Entity * entity)
{
    if (map[loc.x][loc.y].Put_Entity( entity ) == true) {
	return entity;
    } else {
	delete entity;
	return NULL;
    }
}