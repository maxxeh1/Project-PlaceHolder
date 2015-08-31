#pragma once
#ifndef STATES_H
#define STATES_H

#include "StateMachine.h"

class IState
{
	public:
		virtual void update(float elapsed_time);
		virtual void render();
		virtual void onEnter();
		virtual void onExit();
};

class EmptyState: public IState
{
	public:
		EmptyState();

		void update(float elapsed_time);

		void render();

		void onEnter();

		void onExit();
};

class MainMenuState : public IState
{
	public:
		MainMenuState(StateMachine game_mode);

		void update(float elapsed_time);

		void render();

		void onEnter();

		void onExit();
};

class LocalMapState : public IState
{
	public:
		LocalMapState(StateMachine game_mode);

		void update(float elapsed_time);

		void render();

		void onEnter();

		void onExit();
};

class WorldMapState : public IState
{
	public:
		WorldMapState(StateMachine game_mode);

		void update(float elapsed_time);

		void render();

		void onEnter();

		void onExit();
};

class BattleState : public IState
{
	public:
		BattleState(StateMachine game_mode);

		void update(float elapsed_time);

		void render();

		void onEnter();

		void onExit();
};

class InGameMenuState : public IState
{
	public:
		InGameMenuState(StateMachine game_mode);

		void update(float elapsed_time);

		void render();

		void onEnter();

		void onExit();
};

#endif