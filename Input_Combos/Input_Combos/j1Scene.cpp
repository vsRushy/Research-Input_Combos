#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.assign("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	tex_ryu_spritesheet = App->tex->Load("Assets/Textures/ryu_spritesheet.png");

	idle.PushBack({ 7, 14, 59, 90 });

	hadouken.PushBack({ 17, 1417, 74, 90 });
	hadouken.PushBack({ 112, 1417, 85, 90 });
	hadouken.PushBack({ 210, 1417, 90, 90 });
	hadouken.PushBack({ 315, 1417, 106, 90 });
	hadouken.PushBack({ 431, 1417, 126, 90 });
	hadouken.speed = 0.08f;
	hadouken.loop = false;

	shoryuken.PushBack({ 12, 1651, 62, 127 });
	shoryuken.PushBack({ 99, 1651, 68, 127 });
	shoryuken.PushBack({ 176, 1651, 59, 127 });
	shoryuken.PushBack({ 244, 1651, 53, 127 });
	shoryuken.PushBack({ 316, 1651, 48, 127 });
	shoryuken.PushBack({ 369, 1651, 59, 127 });
	shoryuken.speed = 0.08f;
	shoryuken.loop = false;

	current_player_animation = &idle;
	
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	/*if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += floor(200.0f * dt);

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= floor(200.0f * dt);*/

	// Draw ------------------
	App->render->Blit(tex_ryu_spritesheet, 0, 0, &(current_player_animation->GetCurrentFrame()));

	if (current_player_animation->Finished() && current_player_animation != &idle)
	{
		current_player_animation = &idle;
	}

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	App->tex->UnLoad(tex_ryu_spritesheet);

	return true;
}

void j1Scene::SetPlayerAnimation(j1Scene::PLAYER_STATE s)
{
	switch (s)
	{
	case j1Scene::PLAYER_STATE::STATE_IDLE:
		idle.Reset();
		current_player_animation = &idle;
		break;
	case j1Scene::PLAYER_STATE::STATE_HADOUKEN:
		hadouken.Reset();
		current_player_animation = &hadouken;
		break;
	case j1Scene::PLAYER_STATE::STATE_SHORYUKEN:
		shoryuken.Reset();
		current_player_animation = &shoryuken;
		break;
	default:
		break;
	}
}
