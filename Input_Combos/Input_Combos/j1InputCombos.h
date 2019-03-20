#ifndef __J1INPUTCOMBOS_H__
#define __J1INPUTCOMBOS_H__

#include <list>
#include <vector>

#include "j1Module.h"
#include "j1PerfTimer.h"
#include "InputEvent.h"

#define INPUT_MAX_TIME 5000.0f

class InputCombo;

class j1InputCombos : public j1Module
{
public:
	j1InputCombos();
	~j1InputCombos();

	bool Awake(pugi::xml_node& config);

	bool Start();

	bool PreUpdate();
	bool PostUpdate();

	bool CleanUp();

	// ---------

	InputEvent* ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE event_type);

	void DeleteTimingEvents();
	void ClearInputBufferAfterCombo();

	void ClearInputBuffer();
	void ClearCombosVector();

private:
	std::list<InputEvent*> user_input_events;

private:
	std::vector<InputCombo*> combos;
};

#endif // __J1INPUTCOMBOS_H__