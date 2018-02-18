#pragma once
#include "Mesh.h"

namespace pasha
{

	class FileManager
	{
	public:
		static std::string GetExePath()
		{
			char buffer[MAX_PATH];
			GetModuleFileNameA(nullptr, buffer, MAX_PATH);
			std::string::size_type pos = std::string(buffer).find_last_of("\\/");
			std::string path = std::string(buffer).substr(0, pos);
			return path;
		}
	};

	class CubeMesh :public Mesh
	{
	public:
		CubeMesh(IGameObject* game_object, std::string const& mesh_path = FileManager::GetExePath() + R"(\cube.fbx)");

	};

}