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


#include "patype.h"
#include "pa_engine.h"


PandoraEngine::PandoraEngine()
{
    World::_World()->Generate();
}

void PandoraEngine::Run()
{
    
}

Entity* PandoraEngine::Add_Entity(const Location& loc ,Entity * entity)
{
    World_Ptr map;
    if( map(loc).Add_Entity( entity ) == true) {
	return entity;
    } else {
	delete entity;
	return NULL;
    }
}

