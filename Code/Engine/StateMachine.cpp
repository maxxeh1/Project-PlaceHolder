#include <map>
#include <string>

#include "StateMachine.h"

/*
	Update the current state
*/
void StateMachine::update(float elapsed_time)
{
	current_state.update(elapsed_time);
}

/*
	Render the current state
*/
void StateMachine::render()
{
	current_state.render();
}

/*
	Changes the current state
	Add more parameters for onEnter()
	@param state_name: The name of the state to enter
	@param map: The name of the map to use
*/
void StateMachine::change(std::string state_name, std::string map)
{
	current_state.onExit();
	current_state.states[state_name];
	current_state.onEnter();
}

void StateMachine::add(std::string state_name, IState state)
{
	states[state_name] = state;
}
