#include <stdio.h>
#include "Engine.h"
#include "Window.h"
#include "Renderer.h"
#include "RenderComponent.h"
#include "ChaseComponent.h"
#include "Actor.h"

class GameRenderer : public engine::Renderer
{
public:
	GameRenderer(engine::Window& InWindow) : engine::Renderer(InWindow) {}
	void Tick() override;
};

void GameRenderer::Tick()
{
	DrawLine(100, 100, 200, 200);
}

int main(int argc, char **argv)
{
	engine::Engine& Engine = engine::Engine::Get();

	Engine.RegisterComponent<engine::RenderComponent>();
	Engine.RegisterComponent<engine::ChaseComponent>();



	engine::Window Window("Hello World", 1024, 768);

	engine::Actor actor = engine::Actor();

	actor.AddComponent<engine::RenderComponent>();
	actor.AddComponent<engine::RenderComponent>();
	actor.AddComponent<engine::RenderComponent>();
	actor.AddComponent<engine::ChaseComponent>();

	printf("Component Type: %u %u\n", engine::RenderComponent::Type, engine::ChaseComponent::Type);
	GameRenderer Renderer(Window);

	for (;;)
	{
		Window.DequeueEvents();

		auto InRenderComponent = actor.GetComponent<engine::RenderComponent>();
		InRenderComponent->Tick(0);

		auto FoundComponents = actor.GetComponents<engine::RenderComponent>();

		Renderer.Clear();
		Renderer.Tick();

		Renderer.Present();
	}
	return 0;
}