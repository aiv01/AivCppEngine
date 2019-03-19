#pragma once

#include "Window.h"

namespace engine
{
	class Renderer
	{
	public:
		Renderer(Window& InWindow);
		~Renderer();

		Renderer(const Renderer& rhs) = delete;

		virtual void Tick() = 0;

		void Clear() const;
		void Present() const;

		void DrawLine(const int X1, const int Y1, const int X2, const int Y2) const;
	protected:
		Window& Window;
		void *Handle;
	};
}
