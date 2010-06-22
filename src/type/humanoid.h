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


#ifndef HUMANOID_H
#define HUMANOID_H

#include "../patype.h"
#include "../enum/race.h"

class Humanoid : public Creature
{
public:
    Humanoid(const Race);
    String _Description() const;
    Image _Image() const;
    Size _Size() const;
    Size _Max_Holding_Size() const;
    
    bool Chop_Tree() const;
    bool Build_Wall();
    
    Race race;
};

#endif // HUMANOID_H
