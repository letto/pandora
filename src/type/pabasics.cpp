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

boost::uniform_int<> distrib(0, 90090000);// 10000*7*9*11*13
boost::mt19937 engine(static_cast<int_fast32_t>(std::time(0)));
boost::variate_generator<boost::mt19937,boost::uniform_int<>> randgen(engine,distrib);

pa::Image::Image(pa::Char ch, Color color):ch(ch),color(color)
{
}

pa::Color::Color(uint8_t r,uint8_t g,uint8_t b):r(r),g(g),b(b)
{
}

pa::Color::operator SDL_Color()
{
    SDL_Color col = {r,g,b};
    return col;
}

int_fast32_t pa::Random(const int_fast32_t a ,const int_fast32_t b) {
    return randgen()%(b-a+1)+a;
}

int_fast32_t pa::Dice(const int_fast32_t x) {
    return randgen()%x + 1;
}

void pa::Exit(const std::string& msg)
{
    std::cerr << msg << std::endl;
    SDL_Quit();
    exit(1);
}

bool operator>(pa::Size a,pa::Size b) {
    return (pa::Volume)a > (pa::Volume)b;
}

std::string operator+(std::string a, String b) {
    return a + b.get();
}
