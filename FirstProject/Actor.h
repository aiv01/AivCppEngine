#pragma once
#include <vector>
#include <memory>
#include "Component.h"
#include <stdio.h>

namespace engine
{
	class Actor
	{
	public:
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);

		template<typename T>
		std::shared_ptr<T> GetComponent() const
		{
			for (int i = 0; i < Components.size(); i++)
			{
				if (T::Type == Components[i]->ComponentType)
				{
					std::shared_ptr<Component> FoundComponent = Components[i];
					return std::dynamic_pointer_cast<T>(FoundComponent);
				}
			}

			return nullptr;
		}

		template<typename T>
		std::vector<std::shared_ptr<T>> GetComponents() const
		{
			std::vector<std::shared_ptr<T>> FoundComponents;
			for (int i = 0; i < Components.size(); i++)
			{
				if (T::Type == Components[i]->ComponentType)
				{
					auto FoundComponent = std::dynamic_pointer_cast<T>(Components[i]);
					FoundComponents.push_back(FoundComponent);
				}
			}

			return FoundComponents;
		}

		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> NewComponent = std::make_shared<T>();
			InternalAddComponent(NewComponent);
			NewComponent->ComponentType = T::Type;
			printf("assigned ComponentType to %u\n", NewComponent->ComponentType);
			return NewComponent;
		}


	protected:
		std::vector<std::shared_ptr<Component>> Components;

		void InternalAddComponent(std::shared_ptr<Component> Component);
	};
}
