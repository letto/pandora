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


#ifndef ENTITYCONTAINER_H
#define ENTITYCONTAINER_H

#include "../type/entity.h"

class Entity;

class Entity_Iterator
{
public:
	Entity_Iterator(Entity*);
	operator bool();
	Entity* operator*();
	Entity* operator->();
	Entity_Iterator operator++();
	bool operator==(Entity_Iterator);
	bool operator!=(Entity_Iterator);
private:
	Entity* entity;
};

class EntityContainer : virtual public PaObject
{
public:
	EntityContainer(Size);
	~EntityContainer();
	
	bool Has_Space_For(const Entity*) const;
	bool Is_Empty() const;
	bool Has_Entity(const Entity*) const; //expensive: needs to search all the entities
	
	typedef Entity_Iterator iterator;
	
	iterator begin();
	iterator end();
	
	bool Add_Entity(Entity*);
	bool Remove_Entity(Entity*);
	void Insert_Entity(Entity*); //no volume|size checks
	
	Entity* _First_Entity_Except(Entity*);
protected:
	Size::int_t volume_used;
	Size::int_t volume_max;
	
	Entity* entities;
};

#endif // ENTITYCONTAINER_H
