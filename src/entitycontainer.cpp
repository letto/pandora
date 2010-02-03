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

EntityContainer::EntityContainer(Volume volume):volume_max(volume)
,volume_used(0),entities(NULL),entities_it(NULL),entities_display_it(NULL)
{
}

void EntityContainer::Insert_Entity(Entity* entity)
{
    volume_used += (Volume)entity->Get_Size();
    entity->next = entities;
    entity->Set_Holder(this);
    entities = entity;
    entities_display_it = entities;
}

bool EntityContainer::Put_Entity(Entity* entity)
{ 
    if( Has_Space_For(entity)) {
	Insert_Entity(entity);
	return true;
    }
    return false;
}

void EntityContainer::Remove_Entity(Entity* entity) {
    volume_used -= (Volume)entity->Get_Size();
    
    if( entities == entity) {
	entities = entity->next;
    } else {
	Entity* ent  = entities;
	while( ent->next != entity) { 
	    ent = ent->next;
	}
	ent->next = ent->next->next;
    }
    
    entity->next = NULL;
    //entities.remove(entity);
    entities_display_it = entities;
}

bool EntityContainer::Is_Empty() {
    return entities == NULL;
}

bool EntityContainer::Has_Space_For(const Entity* entity) {
    return (Volume)entity->Get_Size() <= volume_max - volume_used;
}

/*Entity* EntityContainer::Get_First_Entity() 
{
}

Entity* EntityContainer::Get_Next_Entity()
{
}*/

Image EntityContainer::Get_Next_Display_Image()
{
    if(Is_Empty()){
	return Get_Image();
    }
    entities_display_it = entities_display_it->next;
    if( entities_display_it == NULL) {
	entities_display_it = entities;
    }
    return entities_display_it->Get_Image();
}