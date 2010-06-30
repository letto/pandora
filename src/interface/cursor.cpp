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

#include "cursor.h"
#include "interface.h"


Cursor::Cursor():
	location(0,0)
{
}

Size Cursor::_Size() const {
    return Size::none;
}

Image Cursor::_Image() const {
    return Image{ 'X', Color::gold};
}

String Cursor::_Description() const {
    return String{"cursor"};
}

Location Cursor::_Location() const {
    if( holder == NULL) {
	return location;
    } else {
	return Entity::_Location();
    }
}

Size Cursor::_Max_Holding_Size() const {
    return Size::none;
}


