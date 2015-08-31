#pragma once
#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include "StateMachine.h"
#include "States.h"

	void setStates(StateMachine game_mode)
	{
		game_mode.add("mainmenu", MainMenuState(game_mode));
		game_mode.add("localmap", LocalMapState(game_mode));
		game_mode.add("worldmap", WorldMapState(game_mode));
		game_mode.add("battle", BattleState(game_mode));
		game_mode.add("ingamemenu", InGameMenuState(game_mode));

		game_mode.change("mainmenu");
	}

	void update(StateMachine game_mode)
	{
		float elapsed_time = GetElapsedFrameTime();
		game_mode.update(elapsed_time);
		game_mode.render();
	}


#endif