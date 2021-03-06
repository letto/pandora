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

#ifndef PAOBJECT_H
#define PAOBJECT_H

#include "pabasics.h"
#include "pastring.h"


class PaObject
{
public:
	PaObject() = default;
	virtual String _Description() const = 0;
	virtual Image _Image() const = 0;
	virtual Location _Location() const = 0;
	virtual ~PaObject() = default;
private:
	PaObject(PaObject&) = delete;
	PaObject& operator=(PaObject&) = delete;
};

#endif // PAOBJECT_H


