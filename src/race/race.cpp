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
#include "race.h"


const Race Race::human 		= String{ "human"};
const Race Race::elf		= String{ "elf"};
const Race Race::orc		= String{ "orc"};
const Race Race::dwarf		= String{ "dwarf"};
const Race Race::high_elf	= String{ "high elf"};
const Race Race::half_elf	= String{ "half elf"};

Race::Race(String s):
	value{s}
{
}

Race::Race(const Race& a):
	value{a.value}
{
}

Race Race::operator=(const Race a) {
    return Race(a.value);
}

bool operator==(const Race a, const Race b) {
    return a.value == b.value;
}

bool operator!=(const Race a, const Race b) {
    return a.value != b.value;
}

Race::operator std::string() const {
    return value.get();
}

std::string operator+(const std::string& s, const Race race) {
    return s + race.value.get();
}

std::string operator+(const Race race, const std::string& s) {
    return race.value.get() + s;
}


bool operator<<=(const Race subrace, const Race race)
{
    if( race == subrace ) {
	return true;
    }
    
    if( race == Race::human ) {
	if( false ) {
	    return true;
	} else {
	    return false;
	}
    }
    
    if( race == Race::elf) {
	if( subrace == Race::half_elf ||
	    subrace == Race::high_elf    ) {
		return true;
	} else {
		return false;
	}
    }
    
    if( race == Race::dwarf ) {
	return false;
    }
    
    if( race == Race::orc ) {
	return false;
    }
    
    // TODO: make this a warning
    Exit("Unreachable place in operator <<=(Race,Race)");
    return false;
}

bool operator>>=(const Race race, const Race subrace) {
    return subrace <<= race;
}

