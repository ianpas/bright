#pragma once
#include "win32app.h"

namespace pasha
{
	class application
	{
	public:
		application(HINSTANCE current, std::wstring title, int show_mode);

	public:
		int main();

		void set_title(std::wstring title);

		RECT get_client();
		HWND get_handle();

	private:
		void virtual run();
		std::shared_ptr<win32app> m_basic_app;

	};

	
}

namespace win32test
{
	class game : public pasha::application
	{
	public:
		game(HINSTANCE current, std::wstring title, int show_mode);

		
	private:
		void run() override;
	};
}