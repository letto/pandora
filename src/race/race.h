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

#include "../type/pastring.h"
#include "../type/pabasics.h"
#include "../type/enum.h"
#include <unordered_map>


class HRace
{
	HRace() = delete;
	typedef int_enum_t int_t;
enum class TRace : int_t  {
    human = 1,
    
    elf,
    high_elf,
    half_elf,
    
    dwarf,
    
    orc
};
public:
class Race :
	public Enum<Race,TRace>
{
public:
static const TRace human	= TRace::human;
static const TRace elf		= TRace::elf;
static const TRace high_elf	= TRace::high_elf;
static const TRace half_elf	= TRace::half_elf;
static const TRace dwarf	= TRace::dwarf;
static const TRace orc		= TRace::orc;
	
	
	Race(const TRace a):Enum<Race,TRace>{a} {}
private:
	friend class Enum<Race,TRace>;
	static bool Init_Map();
	static std::unordered_map< int_t, String> stringmap;
public:
	bool Is_Subrace_Of(const TRace);
	TRace Get_Base_Race();
};
	friend bool Same_Base_Race(const TRace,const TRace);
};

typedef HRace::Race Race;

