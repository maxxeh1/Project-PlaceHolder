#pragma once
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <map>
#include <string>
#include "StateMachine.h"
#include "States.h"

class StateMachine
{
private:
	std::map<std::string, IState> states;
	IState current_state = EmptyState;

public:
	/*
	Update the current state
	*/
	void update(float elapsed_time);

	/*
	Render the current state
	*/
	void render();

	/*
	Changes the current state
	Add more parameters for onEnter()
	@param state_name: The name of the state to enter
	*/
	void change(std::string state_name, std::string map);

	void add(std::string state_name, IState state);
};

#endif