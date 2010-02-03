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

#ifndef ENTITY_H
#define ENTITY_H

#include <map>

#include "pa_basics.h"
#include "pa_object.h"

using pa::Image;
using pa::Size;
using pa::Location;


class Entity : virtual public PaObject
{
public:
    Entity();
    Location Get_Location();
    //Image  Get_Image();
    PaUint Get_ID();
    virtual Size Get_Size() const = 0;
    void Set_Holder(PaObject*);
    Entity* next;
protected:
    PaObject* holder;
    //static Size size;
    
private:
    Entity(const Entity&);
    PaUint id;
    static std::map<PaUint,Entity*> idmap;
};

#endif // ENTITY_H
