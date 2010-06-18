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
#include <unordered_map>



class Race
{
private:
	typedef int_enum_t int_t;
	enum class TRace : int_t 
	{
		human = 1,
		
		elf,
		high_elf,
		half_elf,
		
		dwarf,
		
		orc
	};
public:
static const TRace human	= TRace::human;
static const TRace elf		= TRace::elf;
static const TRace high_elf	= TRace::high_elf;
static const TRace half_elf	= TRace::half_elf;
static const TRace dwarf	= TRace::dwarf;
static const TRace orc		= TRace::orc;
	
	bool Is_Subrace_Of(const TRace);
	TRace Get_Base_Race();
	friend bool Same_Base_Race(const TRace,const TRace);
	
	Race(const TRace);
	Race(const Race&);
	Race operator=(const Race) = delete;
	friend bool operator==(const Race, const Race);
	friend bool operator!=(const Race, const Race);
	friend bool operator==(const Race, const TRace);
	friend bool operator==(const TRace, const Race);
	friend bool operator!=(const Race, const TRace);
	friend bool operator!=(const TRace, const Race);
	
	operator TRace() const;
	operator std::string() const;
	friend std::string operator+(const std::string&, const Race);
	friend std::string operator+(const Race, const std::string&);
private:
	const TRace value;
	static const bool initmap;
	static bool Init_Map();
	static std::unordered_map< int_t, String> racemap;
};

