#include "Actor.h"

void engine::Actor::InternalAddComponent(std::shared_ptr<engine::Component> Component)
{
	this->Components.push_back(Component);
}

void engine::Actor::BeginPlay()
{

}

void engine::Actor::Tick(float DeltaTime)
{

}