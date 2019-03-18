#ifndef __INPUTCOMBOS_H__
#define __INPUTCOMBOS_H__

#include <list>
#include <vector>

#include "j1Module.h"
#include "j1PerfTimer.h"

class InputEvent;

class j1InputCombos : public j1Module
{
public:
	j1InputCombos();
	~j1InputCombos();

	bool Awake(pugi::xml_node&);

	bool Start();

	bool PreUpdate();
	bool PostUpdate();

	bool CleanUp();

private:
	std::list<InputEvent*> user_input_events;

private:
	std::vector<InputEvent*> shoryuken_combo;
	std::vector<InputEvent*> kayoken_combo;
};

#endif // __INPUTCOMBOS_H__