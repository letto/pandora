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


Image Surface::_Image() const {
    return Image{ 9617, Color::dark_green};
}

String Surface::_Description() const {
    return String{"grass surface"};
}

Color Surface::_Color() const {
    return Color::soil_green;
}

Size Surface::_Size() const {
    return Size::tiny;
}


