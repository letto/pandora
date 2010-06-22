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

#ifndef SURFACE_H
#define SURFACE_H

#include "paobject.h"
#include "pabasics.h"
#include "../enum/size.h"
#include "pastring.h"


class Surface //: public PaObject
{
public:
	Color _Color() const;
	Image _Image() const;
	String _Description() const;
	Size _Size() const;
};



#endif // SURFACE_H
