/*
Copyright (C) 2010  Marius Stoica

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "tree.h"

Tree::Tree():Entity()//,EntityContainer(200)
{
}

Image Tree::Get_Image() const {
    return Image(9035,pa::bright_green);
}

std::string Tree::Get_Description() const {
    return "You see a beautiful tree.";
}
Size Tree::Get_Size() const {
    return Size::tree;
}