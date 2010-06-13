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

std::string operator+(const std::string& a,const String b) {
    return a + b.get();
}

std::string Get_Article(const String s) 
{
    auto slen = s.get().length();
    if( slen == 0 ) {
	return "";
    }
    char c0 = '\0',c1 = '\0';
    if( slen >= 1) {
	c0 = s.get()[0];
    }
    if( slen >= 2) {
	c1 = s.get()[1];
    }
    if( c0 == 'h'  &&
	( c1 == 'u'|| c1 == '\0'))  {
	return "a ";
    } else {
	if( c0 == 'h' || c0 == 'a' || c0 == 'e' ||
	    c0 == 'i' || c0 == 'o' || c0 == 'u'    ) {
		return "an ";
	} else {
		return "a ";
	}
    }
}
