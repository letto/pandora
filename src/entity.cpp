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

#include "entity.h"

std::unordered_map<PaUint,Entity*> Entity::idmap;

Entity::Entity():holder(NULL),next(NULL)
{
    static PaUint id_number = 1;
    while(idmap.count(id_number) != 0) {
	id_number++;
    }
    this->id = id_number;
    idmap.insert(std::pair<PaUint,Entity*>( id_number,this));
}

Location Entity::Get_Location() const {
    return holder->Get_Location();
}

PaUint Entity::Get_ID() const {
    return id;
}

void Entity::Set_Holder(EntityContainer* hold) {
    holder = hold;
}

EntityContainer* Entity::Get_Holder() const {
    return holder;
}