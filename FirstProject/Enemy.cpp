#include "Enemy.h"


Enemy::Enemy()
{
	RenderComponent = AddComponent<engine::RenderComponent>();
	ChaseComponent = AddComponent<engine::ChaseComponent>();
	AddComponent<PieraComponent>();
}

void Enemy::Tick(float DeltaTime)
{
	ChaseComponent->Tick(DeltaTime);
}