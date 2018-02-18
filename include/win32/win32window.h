#pragma once

namespace pasha
{
	class window
	{
	public:
		window();
		window(HINSTANCE current, LPCWSTR title, int show_mode);
		static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:
		HWND get_handle();
		RECT get_client();

		void set_title(std::wstring title);

	private:
		HWND m_handle;
		WNDCLASSEXW m_window_class;
	};
}


