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
using std::make_pair;

std::unordered_map<uint32_t, String> Color::colormap;

const Color Color::black	{"black", 	{  0,  0,  0}};
const Color Color::white	{"white", 	{255,255,255}};
const Color Color::red		{"red",		{255,  0,  0}};
const Color Color::green	{"green",	{  0,192,  0}};
const Color Color::blue		{"blue",	{  0,  0,255}};
const Color Color::yellow	{"yellow",	{255,255,  0}};
const Color Color::cyan		{"cyan",	{  0,255,255}};
const Color Color::brown	{"brown",	{184,134, 11}};
const Color Color::tan		{"tan",		{210,180,140}};
const Color Color::orange	{"orange",	{255,165,  0}};
const Color Color::gold		{"gold",	{255,215,  0}};
const Color Color::silver	{"silver",	{192,192,192}};
const Color Color::olive	{"olive",	{ 75,128, 75}};
const Color Color::gray		{"gray",	{127,127,127}};
const Color Color::dark_gray	{"dark gray",	{ 35, 35, 35}};
const Color Color::dark_blue	{"dark blue",	{  0,  0,139}};
const Color Color::dark_cyan	{"dark cyan",	{  0,139,139}};
const Color Color::dark_green	{"dark green",	{  0, 80,  0}};
const Color Color::bright_green	{"bright green",{  0,255,  0}};
const Color Color::soil_green	{"soil green",	{  0, 15,  0}};


Color::Color(const char* s, TColor a):
	value{a}
{
    colormap.insert(make_pair( value, String{s}));
}

Color::TColor::TColor(uint8_t r, uint8_t g, uint8_t b):
	r{r},
	g{g},
	b{b}
{
}

Color::TColor::operator uint32_t () const
{
    uint32_t x = r;
    x <<= 8;
    x += g;
    x <<= 8;
    x += b;
    return x;
}

Color::operator SDL_Color() const {
    return SDL_Color{ value.r, value.g, value.b};
}

Color::operator std::string() const {
    return colormap[value];
}

std::string operator+(const std::string& s,const Color c) {
    return s + (std::string)c;
}

std::string operator+(const Color c,const std::string& s) {
    return (std::string)c + s;
}

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

bool operator>(Size a,Size b) {
    return (Volume)a > (Volume)b;
}
