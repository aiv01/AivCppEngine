#pragma once

namespace engine
{
	class Window
	{
	public:
		Window(const char* Title, const int Width, const int Height);
		~Window();

		Window(const Window& rhs) = delete;

		void* GetHandle() const;

		void DequeueEvents() const;
	protected:
		void* Handle;
	};
}
