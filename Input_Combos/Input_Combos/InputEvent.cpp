#include "InputEvent.h"

InputEvent::InputEvent(CUSTOM_EVENT_TYPE type, bool use_of_timer)
{
	this->type = type;
	if (use_of_timer)
	{
		timer.Start();
	}
}

InputEvent::~InputEvent()
{

}
