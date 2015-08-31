#pragma once
#ifndef STATESTACK_H
#define STATESTACK_H

#include <map>
#include <list>
#include "StateMachine.h"
#include "States.h"

class StateStack
{
	private:
		std::map<std::string, IState> states;
		std::list<IState> game_stack;
		
	public:
		void update(float elapsed_time);

		void render();

		void push(std::string name);

		void pop();
};

#endif