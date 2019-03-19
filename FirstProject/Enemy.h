#pragma once

#include "Actor.h"
#include "RenderComponent.h"
#include "ChaseComponent.h"
#include "PieraComponent.h"

class Enemy : public engine::Actor
{
public:
	Enemy();
	virtual void Tick(float DeltaTime);
protected:
	std::shared_ptr<engine::RenderComponent> RenderComponent;
	std::shared_ptr<engine::ChaseComponent> ChaseComponent;
};
