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

#ifndef PASTRING_H
#define PASTRING_H

#include <string>
#include <boost/flyweight/flyweight.hpp>
#include <boost/flyweight/hashed_factory.hpp>
#include <boost/flyweight/static_holder.hpp>
#include <boost/flyweight/no_locking.hpp>
#include <boost/flyweight/no_tracking.hpp>
typedef boost::flyweights::flyweight<std::string,
		boost::flyweights::hashed_factory<>,
		boost::flyweights::static_holder,
		boost::flyweights::no_locking,
		boost::flyweights::no_tracking> 
	String;


inline std::string operator+(const std::string& a,const String& b) {
    return a + b.get();
}

#endif // PASTRING_H
