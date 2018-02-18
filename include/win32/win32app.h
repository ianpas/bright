#pragma once
#include "win32window.h"

namespace pasha
{
	class win32app
	{
	public:
		win32app(HINSTANCE current, std::wstring title, int show_mode);

	public:
		int main(std::function<void()> __run);

		void set_title(std::wstring title);

		RECT get_client();
		HWND get_handle();

	private:
		void run(std::function<void()> __run);
		std::shared_ptr<window> m_window;

	};
}