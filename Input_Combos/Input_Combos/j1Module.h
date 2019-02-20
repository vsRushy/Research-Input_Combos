#ifndef __j1MODULE_H__
#define __j1MODULE_H__

#include "p2SString.h"

class j1App;

class j1Module
{
public:
	j1Module() : active(false)
	{}

	virtual ~j1Module()
	{}

	void Init()
	{
		active = true;
	}

	// Called before the first frame
	virtual bool Start()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PreUpdate()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool Update(float dt)
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PostUpdate()
	{
		return true;
	}

	// Called before quitting
	virtual bool CleanUp()
	{
		return true;
	}

public:
	p2SString	name;
	bool		active;

};

#endif // __j1MODULE_H__