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


const Color Color::brown	{184,134, 11};
const Color Color::black	{  0,  0,  0};
const Color Color::white	{255,255,255};
const Color Color::red		{255,  0,  0};
const Color Color::green	{  0,192,  0};
const Color Color::blue		{  0,  0,255};
const Color Color::yellow	{255,255,  0};
const Color Color::cyan		{  0,255,255};
const Color Color::orange	{255,165,  0};
const Color Color::tan		{210,180,140};
const Color Color::gold		{255,215,  0};
const Color Color::silver	{192,192,192};
const Color Color::gray		{127,127,127};
const Color Color::olive	{ 75,128, 75};
const Color Color::dark_blue	{  0,  0,139};
const Color Color::dark_cyan	{  0,139,139};
const Color Color::dark_green	{  0, 80,  0};
const Color Color::bright_green	{  0,255,  0};
const Color Color::soil_green	{  0, 15,  0};

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


Color::operator SDL_Color() {
     return SDL_Color{r,g,b};
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

bool operator>(Size a,Size b) {
    return (Volume)a > (Volume)b;
}
