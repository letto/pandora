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

#include "../patype.h"
#include <boost/random.hpp>
#include <ctime>


// This numeber is very divisible
// It is equal to 2^5 * 3^4 * 5^4 * 7 * 11 * 13
boost::uniform_int<> distrib{0, 1621620000};
boost::mt19937 engine{static_cast<int_fast32_t>(std::time(0))};
boost::variate_generator<boost::mt19937,boost::uniform_int<>> randgen{engine,distrib};

Image::Image(Char ch, Color color):
	ch{ch},
	color{color}
{
}

int_fast32_t Random(const int_fast32_t a ,const int_fast32_t b) {
    return randgen()%(b-a+1)+a;
}

int_fast32_t Dice(const int_fast32_t x) {
    return randgen()%x + 1;
}

void Exit(const std::string& msg)
{
    std::cerr << msg << std::endl;
    SDL_Quit();
    exit(1);
}


