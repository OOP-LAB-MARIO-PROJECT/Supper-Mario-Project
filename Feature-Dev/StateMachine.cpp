//#include "StateMachine.h"
//
//namespace Navigator
//{
//	void StateMachine::addState(StateRef newState, bool isReplacing)
//	{
//		_isAdding = true;
//		_isReplacing = isReplacing;
//		_newState = move(newState);
//	}
//
//	void StateMachine::removeState()
//	{
//		_isRemoving = true;
//	}
//
//	void StateMachine::processStateChanges()
//	{
//		if (_isRemoving && !_states.empty())
//		{
//			_states.pop();
//			if (!_states.empty())
//			{
//				_states.top()->resume(); //resume the state that is below the current state
//			}
//			_isRemoving = false; //once we remove the state we set the flag to false
//		}
//
//		if (_isAdding)
//		{
//			if (!_states.empty()) //if we have a state
//			{
//				if (_isReplacing)
//				{
//					_states.pop(); //if we want to replace the current state, we pop the current state
//				}
//				else
//				{
//					_states.top()->pause(); //pause the current state
//				}
//			}
//			_states.push(move(_newState));
//			_states.top()->init(); //initialize the state
//			_isAdding = false; //set the flag to false
//		}
//	}
//	
//	StateRef& StateMachine::getActiveState()
//	{
//		return _states.top(); // return the current state
//	}
//}