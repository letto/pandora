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

#ifndef ENTITYCONTAINER_H
#define ENTITYCONTAINER_H

#include "pa_basics.h"
#include "pa_object.h"

using pa::Location;
using pa::Size;
using pa::Image;
using pa::Volume;

class Entity;

class EntityContainer : virtual public PaObject
{
public:
	EntityContainer(Volume);
	
	bool Has_Space_For(const Entity*);
	bool Is_Empty() const;
	
	bool Add_Entity(Entity*);
	bool Remove_Entity(Entity*);
	void Insert_Entity(Entity*); //no volume|size checks
	
	Entity* Get_First_Entity();
	Entity* Get_First_Entity_Except(Entity*);
	Image Get_Next_Display_Image();
protected:
	Volume volume_used;
	Volume volume_max;
	
	Entity* entities_display_it;
	Entity* entities;
};

#endif // ENTITYCONTAINER_H
