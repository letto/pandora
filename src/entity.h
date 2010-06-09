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

#ifndef ENTITY_H
#define ENTITY_H

#include "pa_basics.h"
#include "container/puid.h"
#include "pa_object.h"

using pa::Image;
using pa::Size;
using pa::Location;

class EntityContainer;

class Entity : virtual public PaObject
{
public:
	Entity();
	Location Get_Location() const;

	virtual Size Get_Size() const = 0;

	Puid id;
	EntityContainer* holder;
private:
	Entity* next;
	friend class EntityContainer;
	friend class Entity_Iterator;
};

#endif // ENTITY_H
