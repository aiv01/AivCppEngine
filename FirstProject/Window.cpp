#include "Window.h"
#include "Private.h"

engine::Window::Window(const char* Title, const int Width, const int Height)
{
	Handle = SDL_CreateWindow(Title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Width, Height, 0);
}

engine::Window::~Window()
{
	SDL_DestroyWindow(reinterpret_cast<SDL_Window *>(Handle));
}

void* engine::Window::GetHandle() const
{
	return Handle;
}

void engine::Window::DequeueEvents() const
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{

	}
}