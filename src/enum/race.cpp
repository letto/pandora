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


HRace::TRace Race::Get_Base_Race()
{
    switch( value ) {
	case Race::human:
	    return Race::human;
	case Race::elf:
	case Race::half_elf:
	case Race::high_elf:
	    return Race::elf;
	case Race::dwarf:
	    return Race::dwarf;
	case Race::orc:
	    return Race::orc;
    }
    // gcc can't tell this is never reached
    return Race::human;
}

bool Race::Is_Subrace_Of(const HRace::TRace race)
{
    switch( race ) {
	case Race::human:
	    if( (int_t)value < (int_t)Race::elf) {
		return true;
	    } else {
		switch(value) {
		    case Race::half_elf:
			return true;
		    default:
			return false;
		}
	    }
	case Race::elf:
	    if( (int_t)value >= (int_t)Race::elf && (int_t)value < (int_t)Race::dwarf) {
		return true;
	    } else {
		return false;
	    }
	case Race::dwarf:
	    if( (int_t)value >= (int_t)Race::dwarf && (int_t)value < (int_t)Race::orc ) {
		return true;
	    } else {
		return false;
	    }
	case Race::orc:
	    if( (int_t)value >= (int_t)Race::orc) {
		return true;
	    } else {
		return false;
	    }
	default:
	    return false;
    }
}

bool Same_Base_Race(const HRace::TRace a,const HRace::TRace b)
{
    if( Race(a).Is_Subrace_Of(Race::human) && Race(b).Is_Subrace_Of(Race::human)) {
	return true;
    }
    return Race(a).Get_Base_Race() == Race(b).Get_Base_Race();
}

