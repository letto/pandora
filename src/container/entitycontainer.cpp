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

#include "entitycontainer.h"
#include "../entity.h"

Entity_Iterator::Entity_Iterator(Entity* entity):
	entity(entity)
{
}

Entity_Iterator::operator bool() {
    return entity != NULL;
}

Entity_Iterator Entity_Iterator::operator++() {
    return Entity_Iterator(entity = entity->next);
}

Entity* Entity_Iterator::operator*() {
    return entity;
}

Entity* Entity_Iterator::operator->() {
    return entity;
}

bool Entity_Iterator::operator==(Entity_Iterator b) {
    return entity == b.entity;
}

bool Entity_Iterator::operator!=(Entity_Iterator b) {
    return !operator==(b);
}

EntityContainer::EntityContainer(Volume volume):
	volume_used(0),
	volume_max(volume),
	entities(NULL)
{
}

Entity_Iterator EntityContainer::begin() {
    return Entity_Iterator(entities);
}

Entity_Iterator EntityContainer::end() {
    return Entity_Iterator(NULL);
}

void EntityContainer::Insert_Entity(Entity* entity)
{
    volume_used += (Volume)entity->Get_Size();
    entity->next = entities;
    entity->holder = this;
    entities = entity;
}

bool EntityContainer::Add_Entity(Entity* entity)
{ 
    if(Has_Space_For(entity)) {
	Insert_Entity(entity);
	return true;
    } else {
	return false;
    }
}

bool EntityContainer::Remove_Entity(Entity* entity)
{
    if(entities == NULL) {
	return false;
    }

    if( entities == entity) {
	entities = entity->next;
    } else {
	Entity* ent  = entities;
	while( ent->next != entity) {
	    ent = ent->next;
	    if (ent == NULL) {
		return false;
	    }
	}
	ent->next = ent->next->next;
    }
    
    entity->next = NULL;
    volume_used -= (Volume)entity->Get_Size();
    return true;
}

bool EntityContainer::Is_Empty() const {
    return entities == NULL;
}

bool EntityContainer::Has_Space_For(const Entity* entity) const {
    return (Volume)entity->Get_Size() <= volume_max - volume_used;
}

bool EntityContainer::Has_Entity(const Entity* entity) const
{
    for( Entity* ent = entities;ent != NULL; ent = ent->next) {
	if( ent == entity) {
	    return true;
	}
    }
    return false;
}

Entity* EntityContainer::Get_First_Entity_Except(Entity* entity)
{
    if(entities == entity) {
	return entity->next;
    } else {
	return entities;
    }
}
