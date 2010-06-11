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

#ifndef PATYPE_H
#define PATYPE_H

#include <typeinfo>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include "type/pabasics.h"
#include "type/pastring.h"
#include "type/paobject.h"
#include "type/entity.h"
#include "type/puid.h"
#include "type/creature.h"
#include "type/item.h"
#include "type/terrain.h"
#include "type/surface.h"

#include "container/entitycontainer.h"
#include "container/world.h"

#endif // PATYPE_H