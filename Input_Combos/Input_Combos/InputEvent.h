#ifndef __INPUTEVENT_H__
#define __INPUTEVENT_H__

#include "j1Module.h"
#include "j1PerfTimer.h"

class InputEvent : public j1Module
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
	InputEvent(CUSTOM_EVENT_TYPE type, float time_limit);
	InputEvent(CUSTOM_EVENT_TYPE type);
	~InputEvent();

private:
	float time_since_start = 0.0f;
	float time_limit = 0.0f;
	CUSTOM_EVENT_TYPE type = CUSTOM_EVENT_TYPE::UNKNOWN;
	j1PerfTimer timer;
};

#endif // __INPUTEVENT_H__