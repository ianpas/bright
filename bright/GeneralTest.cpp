#include "stdafx.h"
#include "GeneralTest.h"

#define key_down(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define key_up(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?0:1)

namespace Bright_Test
{
	GeneralTest::GeneralTest(HINSTANCE current, std::wstring title, int show_mode)
		:application(current, title, show_mode)
	{
		create();
	}

	void GeneralTest::run()
	{
		m_Scene->Render();
	}

	void GeneralTest::create()
	{
		pasha::D2DManager::GetSingleton(get_handle());
		pasha::GraphicsManager::GetSingleton();
		pasha::MeshManager::GetSingleton();

		//
		m_Scene = std::make_unique<pasha::GeneralScene>();


	}
}
