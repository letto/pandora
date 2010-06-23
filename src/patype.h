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

#include <cstdint>
#include <typeinfo>
#include <string>
#include <unordered_map>
using std::unordered_map;
#include <vector>
#include <memory>
#include <iostream>
#include <utility>
using std::make_pair;

#include <boost/lexical_cast.hpp>
using boost::lexical_cast;

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "type/pabasics.h"
#include "type/pastring.h"
#include "enum/color.h"
#include "enum/direction.h"
#include "enum/race.h"
#include "enum/size.h"
#include "type/paobject.h"
#include "type/entity.h"
#include "type/puid.h"
#include "type/creature.h"
#include "type/item.h"
#include "type/terrain.h"
#include "type/surface.h"

#include "container/entitycontainer.h"
#include "world.h"

#endif // PATYPE_H

