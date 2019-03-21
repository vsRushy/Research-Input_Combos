#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"

#include "j1InputCombos.h"
#include "InputCombo.h"

j1InputCombos::j1InputCombos() : j1Module()
{
	name.assign("input_combos");
}

j1InputCombos::~j1InputCombos()
{

}

bool j1InputCombos::Awake(pugi::xml_node& config)
{
	for (pugi::xml_node comb = config.child("combo"); comb; comb = comb.next_sibling("combo"))
	{
		InputCombo* combo = new InputCombo();

		std::string name(comb.attribute("name").as_string());

		if (name == "hadouken")
		{
			combo->combo_name = InputCombo::COMBO_NAME::HADOUKEN;
		}
		else if (name == "shoryuken")
		{
			combo->combo_name = InputCombo::COMBO_NAME::SHORYUKEN;
		}

		for (pugi::xml_node inp = comb.child("input_event"); inp; inp = inp.next_sibling("input_event"))
		{
			std::string event_name;
			event_name.assign(inp.attribute("type").as_string());

			InputEvent::CUSTOM_EVENT_TYPE event_type = InputEvent::CUSTOM_EVENT_TYPE::UNKNOWN;

			if (event_name == "left")
				event_type = InputEvent::CUSTOM_EVENT_TYPE::LEFT;
			else if (event_name == "up")
				event_type = InputEvent::CUSTOM_EVENT_TYPE::UP;
			else if (event_name == "right")
				event_type = InputEvent::CUSTOM_EVENT_TYPE::RIGHT;
			else if (event_name == "down")
				event_type = InputEvent::CUSTOM_EVENT_TYPE::DOWN;
			else if (event_name == "punch")
				event_type = InputEvent::CUSTOM_EVENT_TYPE::PUNCH;
			else if (event_name == "kick")
				event_type = InputEvent::CUSTOM_EVENT_TYPE::KICK;

			InputEvent* input_event = new InputEvent(event_type);
			combo->FillComboChain(input_event);
		}

		combos.push_back(combo);
	}

	return true;
}

bool j1InputCombos::Start()
{


	return true;
}

bool j1InputCombos::PreUpdate()
{
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
	{
		user_input_events.push_back(ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE::LEFT));
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN)
	{
		user_input_events.push_back(ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE::UP));
	}
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
	{
		user_input_events.push_back(ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE::RIGHT));
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		user_input_events.push_back(ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE::DOWN));
	}
	if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN)
	{
		user_input_events.push_back(ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE::PUNCH));
	}
	if (App->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN)
	{
		user_input_events.push_back(ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE::KICK));
	}

	/*LOG("<<<<<<< INPUT EVENTS LIST: %i", user_input_events.size());
	if (user_input_events.size() > 0)
		LOG("<<<<<<< INPUT EVENTS TYPE: %i", user_input_events.front()->type);*/
	
	return true;
}

bool j1InputCombos::PostUpdate()
{
	// Check combos done
	ClearInputBufferAfterCombo();

	// Delete timing events after max time
	DeleteTimingEvents();

	return true;
}

bool j1InputCombos::CleanUp()
{
	ClearInputBuffer();
	ClearCombosVector();

	return true;
}

InputEvent* j1InputCombos::ReturnEvent(InputEvent::CUSTOM_EVENT_TYPE event_type)
{
	return new InputEvent(event_type, true);
}

void j1InputCombos::DeleteTimingEvents()
{
	if (user_input_events.size() > 0)
	{
		std::list<InputEvent*>::const_iterator item = user_input_events.begin();
		while (item != user_input_events.end())
		{
			if ((*item)->timer.ReadMs() > INPUT_MAX_TIME)
			{
				delete *item;
				item = user_input_events.erase(item);
			}
			else
			{
				++item;
			}
		}
	}
}

void j1InputCombos::ClearInputBufferAfterCombo()
{
	if (user_input_events.size() > 0)
	{
		for (std::vector<InputCombo*>::const_iterator item = combos.begin(); item != combos.end(); item++)
		{
			if ((*item)->CheckCommonInput(user_input_events))
			{
				InputCombo::COMBO_NAME temp_name = (*item)->combo_name;
				switch (temp_name)
				{
				case InputCombo::COMBO_NAME::HADOUKEN:
					App->scene->SetPlayerAnimation(j1Scene::PLAYER_STATE::STATE_HADOUKEN);
					break;
				case InputCombo::COMBO_NAME::SHORYUKEN:
					App->scene->SetPlayerAnimation(j1Scene::PLAYER_STATE::STATE_SHORYUKEN);
					break;
				default:
					break;
				}

				ClearInputBuffer();
			}
		}
	}
}

void j1InputCombos::ClearInputBuffer()
{
	for (std::list<InputEvent*>::const_iterator item = user_input_events.begin(); item != user_input_events.end(); item++)
	{
		delete *item;
	}

	user_input_events.clear();
}

void j1InputCombos::ClearCombosVector()
{
	for (std::vector<InputCombo*>::const_reverse_iterator item = combos.rbegin(); item != combos.rend(); item++)
	{
		delete *item;
	}
	combos.clear();
}
