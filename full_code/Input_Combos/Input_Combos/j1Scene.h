#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "SDL/include/SDL_rect.h"

#include "j1Module.h"
#include "Animation.h"

struct SDL_Texture;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


public:
	enum class PLAYER_STATE
	{
		STATE_UNKNOWN = -1,
		STATE_IDLE,
		STATE_HADOUKEN,
		STATE_SHORYUKEN
	};

	void SetPlayerAnimation(j1Scene::PLAYER_STATE s);

private:
	// Character spritesheet
	SDL_Texture* tex_ryu_spritesheet = nullptr;

	// Animations
	Animation* current_player_animation = nullptr;
	Animation idle;
	Animation hadouken;
	Animation shoryuken;
};

#endif // __j1SCENE_H__