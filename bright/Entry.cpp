#include "stdafx.h"
#include "GeneralTest.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
	return Bright_Test::GeneralTest{ hInstance, L"Bright", nCmdShow }.main();
}