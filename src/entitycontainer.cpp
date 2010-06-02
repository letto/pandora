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

#include "entitycontainer.h"
#include "entity.h"

EntityContainer::EntityContainer(Volume volume):
	volume_used(0),
	volume_max(volume),
	entities_display_it(NULL),
	entities(NULL)
{
}

void EntityContainer::Insert_Entity(Entity* entity)
{
    volume_used += (Volume)entity->Get_Size();
    entity->next = entities;
    entity->holder = this;
    entities = entity;
    entities_display_it = entities;
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
    entities_display_it = entities;
    volume_used -= (Volume)entity->Get_Size();
    return true;
}

bool EntityContainer::Is_Empty() const {
    return entities == NULL;
}

bool EntityContainer::Has_Space_For(const Entity* entity) {
    return (Volume)entity->Get_Size() <= volume_max - volume_used;
}

Entity* EntityContainer::Get_First_Entity() {
    return entities;
}

Entity* EntityContainer::Get_First_Entity_Except(Entity* entity)
{
    if(entities == entity) {
	return entity->next;
    } else {
	return entities;
    }
}

Image EntityContainer::Get_Next_Display_Image()
{
    if(Is_Empty()) {
	return Get_Image();
    }
    entities_display_it = entities_display_it->next;
    if( entities_display_it == NULL) {
	entities_display_it = entities;
    }
    return entities_display_it->Get_Image();
}

