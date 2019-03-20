#ifndef __INPUTCOMBO_H__
#define __INPUTCOMBO_H__

#include <vector>
#include <list>

class InputEvent;

class InputCombo
{
public:
	enum class COMBO_NAME
	{
		HADOUKEN,
		SHORYUKEN
	};

public:
	InputCombo();
	~InputCombo();

	void FillComboChain(InputEvent* input_event);

	bool CheckCommonInput(std::list<InputEvent*> input_event);

public:
	std::vector<InputEvent*> vector_item;
	COMBO_NAME combo_name;
};

#endif // __INPUTCOMBO_H__