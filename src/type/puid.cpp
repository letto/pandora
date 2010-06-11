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

#include "../patype.h"

std::unordered_map<uint64_t,Entity*> Puid::idmap;

Puid::Puid(Entity* ent)
{
    static uint64_t id_number = 1;
    while(idmap.count(id_number) != 0) {
	id_number++;
    }
    id = id_number;
    
    idmap.insert(std::pair<uint64_t,Entity*>( id, ent));
}

Puid::~Puid()
{
    idmap.erase(id);
}


std::string Puid::get() const {
    return boost::lexical_cast<std::string>(id);
}
