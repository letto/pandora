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

#ifndef SIZE_H
#define SIZE_H

#include "pabasics.h"
#include "enum.h"

class HSize 
{
	HSize() = delete;
	typedef int_enum_t int_t;
enum class TSize : int_t {
    none = 0,
    tiny = 1, //insects
    small = 16, //cats
    medium = 64, //dogs
    large = 128, //humans
    huge = 256, //elephants
    gigantic = 1024, //
    
    tree = 132,
    terrain = 350
};
public:
class Size :
	public Enum<Size,TSize>,
	public Comparable<Size,TSize>
{
public:
	typedef HSize::int_t int_t;
static const TSize none =	TSize::none;
static const TSize tiny =	TSize::tiny;
static const TSize small =	TSize::small;
static const TSize medium =	TSize::medium;
static const TSize large =	TSize::large;
static const TSize huge =	TSize::huge;
static const TSize gigantic =	TSize::gigantic;
static const TSize tree =	TSize::tree;
static const TSize terrain =	TSize::terrain;
	
	
	Size(const TSize a):Enum<Size,TSize>{a} {}
	operator int_t() const { return (int_t)value;}
private:
	friend class Enum<Size,TSize>;
	static bool Init_Map();
	static std::unordered_map< int_t, String> stringmap;
public:

};
};

typedef HSize::Size Size;

#endif // SIZE_H
