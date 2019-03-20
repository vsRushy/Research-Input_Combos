#ifndef __INPUTEVENT_H__
#define __INPUTEVENT_H__

#include "j1Module.h"
#include "j1PerfTimer.h"

class InputEvent
{
public:
	enum class CUSTOM_EVENT_TYPE
	{
		UNKNOWN = -1,

		LEFT,
		RIGHT,
		UP,
		DOWN,
		PUNCH,
		KICK
	};

public:
	InputEvent(CUSTOM_EVENT_TYPE type, bool use_of_timer = false);
	~InputEvent();

public:
	j1PerfTimer timer;
	CUSTOM_EVENT_TYPE type = CUSTOM_EVENT_TYPE::UNKNOWN;
};

#endif // __INPUTEVENT_H__
