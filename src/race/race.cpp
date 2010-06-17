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
using std::make_pair;

std::unordered_map< Race::int_t, String> Race::racemap;

const bool Race::initmap = Race::Init_Map();

bool Race::Init_Map()
{
    // use switch so that compiler warns on missing values
    volatile TRace a = TRace::human;
    switch(a) {
	case TRace::human:
	    racemap.insert(make_pair((int_t)TRace::human,	String{"human"}));
	case TRace::elf:
	    racemap.insert(make_pair((int_t)TRace::elf,		String{"elf"}));
	case TRace::orc:
	    racemap.insert(make_pair((int_t)TRace::orc,		String{"orc"}));
	case TRace::dwarf:
	    racemap.insert(make_pair((int_t)TRace::dwarf,	String{"dwarf"}));
	    
	case TRace::high_elf:
	    racemap.insert(make_pair((int_t)TRace::high_elf,	String{"high elf"}));
	case TRace::half_elf:
	    racemap.insert(make_pair((int_t)TRace::half_elf,	String{"half elf"}));
    }
    return true;
}

Race::Race(const TRace race):
	value{race}
{
}

Race::Race(const Race& a):
	value{a.value}
{
}

bool operator==(const Race a, const Race b) {
    return a.value == b.value;
}

bool operator!=(const Race a, const Race b) {
    return a.value != b.value;
}

bool operator==(const Race a,const Race::TRace b) {
    return a.value == b;
}

bool operator==(const Race::TRace a,const Race b) {
    return a == b.value;
}

bool operator!=(const Race a,const Race::TRace b) {
    return a.value != b;
}

bool operator!=(const Race::TRace a,const Race b) {
    return a != b.value;
}

Race::operator TRace() const {
    return value;
}

Race::operator std::string() const {
    return racemap[(int_t)value];
}

std::string operator+(const std::string& s, const Race race) {
    return s + (std::string)race;
}

std::string operator+(const Race race, const std::string& s) {
    return (std::string)race + s;
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
