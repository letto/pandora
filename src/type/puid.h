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

#ifndef PUID_H
#define PUID_H

#include <unordered_map>
#include <cstdint>
#include <string>

class Entity;

class Puid
{
public:
	Puid(Entity*);
	~Puid();
	operator std::string() const;
private:
	uint64_t id;
	static std::unordered_map<uint64_t,Entity*> idmap;
	
	operator int() = delete;
	Puid(Puid&) = delete;
	Puid operator=(Puid&) = delete;
};

#endif // PUID_H


