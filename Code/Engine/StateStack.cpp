#include "StateStack.h"

void StateStack::update(float elapsed_time)
{
	IState front = game_stack.front();
	front.update(elapsed_time);
}

void StateStack::render()
{
	IState front = game_stack.front();
	front.render();
}

void StateStack::push(std::string name)
{
	IState state = states[name];
	game_stack.push_front(state);
}

void StateStack::pop()
{
	return game_stack.pop_front();
}