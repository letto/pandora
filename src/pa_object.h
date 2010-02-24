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

#ifndef PAOBJECT_H
#define PAOBJECT_H

#include "pa_basics.h"

using pa::Image;
using pa::Location;

class PaObject
{
public:
	virtual std::string Get_Description() const = 0;
	virtual Image Get_Image() const = 0;
	virtual Location Get_Location() const = 0;
protected:
	PaObject();
private:
	//PaObject(PaObject&);
	//PaObject& operator=(const PaObject&);
};

#endif // PAOBJECT_H
