#pragma once

#include <stdio.h>

namespace engine
{
	class Engine
	{
	private:
		Engine();
		unsigned int ComponentCounter;

	public:
		static Engine& Get();
		~Engine();

		template<typename T>
		void RegisterComponent()
		{
			T::Type = ++ComponentCounter;
			printf("assigned %u to the new type\n", T::Type);
		}
	};
}
