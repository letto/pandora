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

#ifndef CREATURE_H
#define CREATURE_H

#include "pabasics.h"
#include "../enum/direction.h"
#include "entity.h"


class Creature :
	public Entity
{
public:
	Creature();
	~Creature();
	bool Go_Direction(const Direction&);
	virtual Size _Max_Holding_Size() const = 0;

	bool Take_Entity(Entity*);
	bool Drop_Entity();
	Entity* holding;
};

#endif // CREATURE_H


