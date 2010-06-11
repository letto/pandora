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


#ifndef CURSOR_H
#define CURSOR_H

#include "../type/pabasics.h"
#include "../type/creature.h"

class Cursor : public Creature
{
public:
	Size Get_Size() const;
	pa::Image Get_Image() const;
	String Get_Description() const;
	Size Get_Max_Holding_Size() const;
};

#endif // CURSOR_H
