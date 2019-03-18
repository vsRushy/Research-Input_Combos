#include "InputEvent.h"

InputEvent::InputEvent(CUSTOM_EVENT_TYPE type, float time_limit)
{
	this->type = type;
	this->time_limit = time_limit;
}

InputEvent::InputEvent(CUSTOM_EVENT_TYPE type)
{
	this->type = type;
	this->timer.Start();
}

InputEvent::~InputEvent()
{

}