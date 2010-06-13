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

#include "../type/pastring.h"

class Race
{
public:
static const Race
	human,
	elf,
	orc,
	dwarf,
	
	high_elf,
	half_elf;
	
	
	Race(const Race&);
	Race operator=(const Race);
	friend bool operator==(const Race, const Race);
	friend bool operator!=(const Race, const Race);
	
	operator std::string() const;
	friend std::string operator+(const std::string&, const Race);
	friend std::string operator+(const Race, const std::string&);
private:
	String value;
	Race(String);
};

bool operator==(const Race, const Race);
bool operator!=(const Race, const Race);

std::string operator+(const std::string&, const Race);
std::string operator+(const Race, const std::string&);

// is subrace of 
bool operator<<=(const Race, const Race);
bool operator>>=(const Race, const Race);

