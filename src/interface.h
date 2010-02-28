/*
Copyright (C) 2010  Marius Stoica

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "terminal.h"
#include "pa_engine.h"
#include "race/race.h"
#include "cursor.h"

class Interface
{
public:
	Interface();
	~Interface();
	void Run();
private:
	Terminal display;
	Terminal events;
	Terminal info;
	Terminal actions;
	
	PaUint display_counter;
	void Draw_Display();
	void Draw_Info();
	void Draw_Actions();
	
	bool action_succes;
	enum class Mode { online , cursor} mode;
	enum class Action {none,move} action_type;
	enum class FollowMode {centered,following,controlled} follow_mode;
	Location cursor_loc;
	PaUint player_id;
	Humanoid* player;
	Humanoid* Add_Player(const Location&,Entity*);
	Cursor* cursor;
	Creature* current_ent;
	
	
	PandoraEngine engine;
	
	
	SDL_Surface* screen;
	int video_Flags;
	void Resize();
	void Event_Handler(const SDL_Event&);
	static int Event_Filter(const SDL_Event* const);
	void Keyboard_Handler(const SDL_keysym&);
};

#endif // INTERFACE_H
