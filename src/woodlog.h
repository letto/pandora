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

#ifndef WOODLOG_H
#define WOODLOG_H

#include "pa_basics.h"
#include "entity.h"

using pa::Image;

class WoodLog : public Entity
{
public:
	//WoodLog();
	Size Get_Size() const;
	Image Get_Image() const;
	std::string Get_Description() const;
};

#endif // WOODLOG_H
