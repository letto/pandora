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
#include "size.h"

unordered_map< Size::int_t, String> Size::stringmap;
template<> const bool Enum<Size, HSize::TSize>::init_map = Size::Init_Map();


bool Size::Init_Map()
{
    TSize a = TSize::none;
    switch( a ) {
	case Size::none:
	    stringmap.insert(make_pair((int_t)Size::none,	String{"none"}));
	case Size::tiny:
	    stringmap.insert(make_pair((int_t)Size::tiny,	String{"tiny"}));
	case Size::small:
	    stringmap.insert(make_pair((int_t)Size::small,	String{"small"}));
	case Size::medium:
	    stringmap.insert(make_pair((int_t)Size::medium,	String{"medium"}));
	case Size::large:
	    stringmap.insert(make_pair((int_t)Size::large,	String{"large"}));
	case Size::huge:
	    stringmap.insert(make_pair((int_t)Size::huge,	String{"huge"}));
	case Size::gigantic:
	    stringmap.insert(make_pair((int_t)Size::gigantic,	String{"gigantic"}));
	case Size::tree:
	    stringmap.insert(make_pair((int_t)Size::tree,	String{"tree"}));
	case Size::terrain:
	    stringmap.insert(make_pair((int_t)Size::terrain,	String{"terrain"}));
    }
    return true;
}

