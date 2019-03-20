#include "j1InputCombos.h"
#include "InputCombo.h"
#include "InputEvent.h"

InputCombo::InputCombo()
{

}

InputCombo::~InputCombo()
{

}

void InputCombo::FillComboChain(InputEvent* input_event)
{
	vector_item.push_back(input_event);
}

bool InputCombo::CheckCommonInput(std::list<InputEvent*> input_event)
{
	std::vector<InputEvent*>::const_iterator combo_item = vector_item.begin();

	bool common_input_events_exist = false;

	for (std::list<InputEvent*>::const_iterator list_item = input_event.begin(); list_item != input_event.end(); list_item++)
	{
		common_input_events_exist = false;
		combo_item = vector_item.begin();
		while (combo_item != vector_item.end()) 
		{
			if ((*list_item)->timer.ReadMs() <= INPUT_MAX_TIME && (*list_item)->type == (*combo_item)->type) 
			{
				if ((*combo_item) == vector_item.back()) 
				{
					return true;
				}
				else 
				{
					if ((*list_item) == input_event.back())
						break;
					combo_item++;
					list_item++;
					continue;
				}
			}
			else
			{
				common_input_events_exist = true;
			}

			if (common_input_events_exist || (*list_item) == input_event.back())
			{
				break;
			}
			
			list_item++;
		}
	}

	return false;
}
