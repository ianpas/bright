#pragma once
#include "IMeshManager.h"
#include <fbxsdk.h>

namespace pasha
{
	class FbxManager : public IMeshManager
	{
	public:
		void						ImportMesh(std::string const& mesh_path) override;
		std::vector<Vertex>			GetVertices() const override;
		std::vector<unsigned int>	GetIndices() const override;

	public:
		~FbxManager();

	private:
		::FbxManager*				m_FbxManager;
		::FbxScene*					m_Scene;

	public:
		FbxManager(FbxManager const&) = delete;
		FbxManager& operator=(FbxManager const&) = delete;
		static FbxManager& GetSingleton();

	private:
		FbxManager();
		static std::unique_ptr<FbxManager> Singleton;
		static std::once_flag OnceFlag;
	};
}