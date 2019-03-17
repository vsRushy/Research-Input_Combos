#ifndef __INPUTEVENT_H__
#define __INPUTEVENT_H__

#include "j1Module.h"

class InputEvent : public j1Module
{
public:
	InputEvent();
	~InputEvent();

private:
	enum CUSTOM_EVENT_TYPE
	{
		UNKNOWN = 0,

		LEFT,
		RIGHT,
		UP,
		DOWN,
		PUNCH,
		KICK
	};
};

#endif // __INPUTEVENT_H__