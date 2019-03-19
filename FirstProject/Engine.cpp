#include "Engine.h"
#include "Private.h"

engine::Engine::Engine()
{
	SDL_Init(SDL_INIT_VIDEO);
	ComponentCounter = 0;
}

engine::Engine& engine::Engine::Get()
{
	static Engine* Singleton = nullptr;

	if (!Singleton)
	{
		Singleton = new Engine();
	}

	return *Singleton;
}

engine::Engine::~Engine()
{
	SDL_Quit();
}