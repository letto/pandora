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

#ifndef ENUM_H
#define ENUM_H

#include <string>

template<class T,class TEnum>
class Enum
{
public:
    Enum(TEnum a):value{a} {};
    Enum() = delete;
    Enum operator=(const Enum&) = delete;
    
    operator TEnum() const {
	return value;
    }
    friend bool operator==(const T a, const T b) {
	return (TEnum)a == (TEnum)b;
    }
    friend bool operator!=(const T a, const T b) {
	return (TEnum)a != (TEnum)b;
    }
    friend bool operator==(const T a, const TEnum b) {
	return (TEnum)a == b;
    }
    friend bool operator==(const TEnum a, const T b) {
	return a == (TEnum)b;
    }
    friend bool operator!=(const T a, const TEnum b) {
	return (TEnum)a != b;
    }
    friend bool operator!=(const TEnum a, const T b) {
	return a != (TEnum)b;
    }
    
    operator std::string() const {
	static_assert(sizeof(TEnum) <= sizeof(int32_t),"truncated casting");
	return T::stringmap[(int32_t)operator TEnum()];
    }
    friend std::string operator+(const std::string& s, const T t) {
	return s + (std::string)t;
    }
    friend std::string operator+(const T t, const std::string& s) {
	return (std::string)t + s;
    }
protected:
	static const bool init_map;
	TEnum value;
};

template<class T,class TEnum>
class Comparable
{
public:
    friend bool operator>(T a, T b) {
	return a > b;
    }
    friend bool operator>=(T a, T b) {
	return a >= b;
    }
    friend bool operator<(T a, T b) {
	return a < b;
    }
    friend bool operator<=(T a, T b) {
	return a <= b;
    }
    
    
    friend bool operator>(T a, TEnum b) {
	return a > b;
    }
    friend bool operator>=(T a, TEnum b) {
	return a >= b;
    }
    friend bool operator<(T a, TEnum b) {
	return a < b;
    }
    friend bool operator<=(T a, TEnum b) {
	return a <= b;
    }
    
    
    friend bool operator>(TEnum a, T b) {
	return a > b;
    }
    friend bool operator>=(TEnum a, T b) {
	return a >= b;
    }
    friend bool operator<(TEnum a, T b) {
	return a < b;
    }
    friend bool operator<=(TEnum a, T b) {
	return a <= b;
    }
    
    
    friend bool operator>(TEnum a, TEnum b) {
	return a > b;
    }
    friend bool operator>=(TEnum a, TEnum b) {
	return a >= b;
    }
    friend bool operator<(TEnum a, TEnum b) {
	return a < b;
    }
    friend bool operator<=(TEnum a, TEnum b) {
	return a <= b;
    }
};

#endif // ENUM_H
