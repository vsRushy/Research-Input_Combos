#ifndef __INPUTCOMBOS_H__
#define __INPUTCOMBOS_H__

#include "j1Module.h"

#include "j1PerfTimer.h"

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
	// std::vector<InputEvent*> events;

private:

};

#endif // __INPUTCOMBOS_H__