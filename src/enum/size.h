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

#ifndef SIZE_H
#define SIZE_H

#include "../type/pabasics.h"
#include "enum.hpp"


#define ENUM_CLASS 	Size
#define ENUM_ADJECTIVE 	"sized"
#undef  ENUM_PROPERTIES
#define ENUM_PROPERTIES (Comparable)
#define ENUM_VALUES	\
    (( none	)( = 0	))\
    (( tiny	)( = 1	))\
    (( small	)( = 16	))\
    (( medium	)( = 64	))\
    (( large	)( = 128))\
    (( huge	)( = 256))\
    (( gigantic	)( =1024))\
    (( tree	)( = 132))\
    (( terrain	)( = 350))


ENUM_BEGIN
	operator int_t() const { return (int_t)value;}
};
ENUM_END

#include "undef.h"

#endif // SIZE_H

