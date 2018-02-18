#pragma once
#include "application.h"
#include "GeneralScene.h"

namespace Bright_Test
{
	class GeneralTest : public pasha::application
	{
	public:
		GeneralTest(HINSTANCE current, std::wstring title, int show_mode);

	private:
		void run() override;
		void create();


	private:
		std::unique_ptr<pasha::IScene>					m_Scene;
		
	};

}



