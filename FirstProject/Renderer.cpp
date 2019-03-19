#include "Renderer.h"
#include "Private.h"

engine::Renderer::Renderer(engine::Window& InWindow) : Window(InWindow)
{
	SDL_Window* WindowHandle =
		reinterpret_cast<SDL_Window*>(Window.GetHandle());
	Handle = SDL_CreateRenderer(WindowHandle, -1, 0);
}

engine::Renderer::~Renderer()
{
	SDL_DestroyRenderer(reinterpret_cast<SDL_Renderer*>(Handle));
}

void engine::Renderer::Clear() const
{
	SDL_SetRenderDrawColor(reinterpret_cast<SDL_Renderer*>(Handle), 0, 0, 0, 255);
	SDL_RenderClear(reinterpret_cast<SDL_Renderer*>(Handle));
}

void engine::Renderer::Present() const
{
	SDL_RenderPresent(reinterpret_cast<SDL_Renderer*>(Handle));
}

void engine::Renderer::DrawLine(const int X1, const int Y1, const int X2, const int Y2) const
{
	SDL_SetRenderDrawColor(reinterpret_cast<SDL_Renderer*>(Handle), 255, 0, 0, 255);
	SDL_RenderDrawLine(reinterpret_cast<SDL_Renderer*>(Handle), X1, Y1, X2, Y2);
}