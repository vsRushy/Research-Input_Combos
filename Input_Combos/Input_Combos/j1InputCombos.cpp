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
#include "InputEvent.h"

j1InputCombos::j1InputCombos() : j1Module()
{

}

j1InputCombos::~j1InputCombos()
{

}

bool j1InputCombos::Awake(pugi::xml_node&)
{
	return true;
}

bool j1InputCombos::Start()
{
	shoryuken_combo.push_back(new InputEvent(InputEvent::CUSTOM_EVENT_TYPE::DOWN, 1500.0f));
	shoryuken_combo.push_back(new InputEvent(InputEvent::CUSTOM_EVENT_TYPE::RIGHT, 1500.0f));
	shoryuken_combo.push_back(new InputEvent(InputEvent::CUSTOM_EVENT_TYPE::KICK, 1500.0f));

	return true;
}

bool j1InputCombos::PreUpdate()
{
	return true;
}

bool j1InputCombos::PostUpdate()
{
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		user_input_events.push_back(new InputEvent(InputEvent::CUSTOM_EVENT_TYPE::DOWN));
	}

	return true;
}

bool j1InputCombos::CleanUp()
{
	for (std::vector<InputEvent*>::const_reverse_iterator item = shoryuken_combo.rbegin(); item != shoryuken_combo.rend(); item++)
	{
		delete *item;
	}
	shoryuken_combo.clear();


	return true;
}