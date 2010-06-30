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

#ifndef RACE_H
#define RACE_H

#include "enum.hpp"

ENUM_CLASS( Race, "", ,
    ((human)(= 1))
    ((elf	))
    ((high_elf	))
    ((half_elf	))
    ((dwarf	))
    ((orc	))
    ,
	bool Is_Subrace_Of(const TRace);
	Race Get_Base_Race();
    ,
	friend bool Same_Base_Race(const TRace,const TRace);
)

#endif // RACE_H

