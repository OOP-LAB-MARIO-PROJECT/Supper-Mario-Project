#pragma once
#include <memory>
#include <stack>
#include "States.h"
#include <stack>
using namespace std;
namespace Navigator
{
	typedef std::unique_ptr<States> StateRef;
	class StateMachine
	{
	public:
		StateMachine() {}
		~StateMachine() {}

		void addState(StateRef newState, bool isReplacing = true); //which means are you replacing the current state that is available
		void removeState();

		void processStateChanges(); //runs at the start of each loop
		StateRef& getActiveState();

		StateRef& getActiveState(); //return the top level state 

	private:
		stack<StateRef> _states; //stack of states
		StateRef _newState; //the latest state to add

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing; //these track if we're adding , removing or replacing a state

	};
}

