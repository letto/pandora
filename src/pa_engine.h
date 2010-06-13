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

#ifndef PA_ENGINE_H
#define PA_ENGINE_H

#include "patype.h"


class PandoraEngine
{
public:
	PandoraEngine();
	void Run();
	Entity* Add_Entity(const Location& ,Entity*);
	int16_t Get_Map_Max_X();
	int16_t Get_Map_Max_Y();
private:
	
};

#endif // PA_ENGINE_H
