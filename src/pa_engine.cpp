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

World map{431,463};

PandoraEngine::PandoraEngine()
{
    map.Generate();
}

void PandoraEngine::Run()
{
    
}

int16_t PandoraEngine::Get_Map_Max_X(){
    return map.max_x;
}

int16_t PandoraEngine::Get_Map_Max_Y(){
    return map.max_y;
}

Entity* PandoraEngine::Add_Entity(const Location& loc ,Entity * entity)
{
    if (map(loc).Add_Entity( entity ) == true) {
	return entity;
    } else {
	delete entity;
	return NULL;
    }
}