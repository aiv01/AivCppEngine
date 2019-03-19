#pragma once

namespace engine
{
	class Component
	{
	public:
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);

		unsigned int ComponentType;
	};
}