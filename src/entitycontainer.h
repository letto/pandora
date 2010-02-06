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

//#include<list>
#include <forward_list>
#include "pa_basics.h"
#include "pa_object.h"
#include "entity.h"

using pa::Location;
using pa::Size;
using pa::Image;
using pa::Volume;

class EntityContainer : virtual public PaObject
{
public:
	EntityContainer(Volume);
	
	bool Has_Space_For(const Entity*);
	bool Is_Empty() const;
	void Insert_Entity(Entity*);
	bool Put_Entity(Entity*);
	void Remove_Entity(Entity*);
	
	Entity* Get_First_Entity();
	//Entity* Get_Next_Entity();
	Image Get_Next_Display_Image();
private:
	Volume volume_used;
	Volume volume_max;
	
	Entity* entities_display_it;
	Entity* entities_it;
	Entity* entities;
};

#endif // ENTITYCONTAINER_H
