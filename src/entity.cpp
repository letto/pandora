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

#include "entity.h"
#include "container/entitycontainer.h"

Entity::Entity():
    id(this),
    next(NULL),
    holder(NULL)
{
}

Location Entity::Get_Location() const {
    return holder->Get_Location();
}

Entity* Entity::Get_Next_Entity_Except(Entity* entity)
{
    if(next == entity) {
	return next->next;
    } else {
	return next;
    }
}
