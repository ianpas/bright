#pragma once
#include "FbxManager.h"

namespace pasha
{
	class MeshManager : public IMeshManager
	{
	public:
		virtual ~MeshManager() = default;

	public:
		void ImportMesh(std::string const & mesh_path) override;
		std::vector<Vertex> GetVertices() const override;
		std::vector<unsigned int> GetIndices() const override;

	public:
		MeshManager(MeshManager const&) = delete;
		MeshManager& operator=(MeshManager const&) = delete;
		static MeshManager& GetSingleton();

	private:
		MeshManager();
		static std::unique_ptr<MeshManager> Singleton;
		static std::once_flag OnceFlag;


	};
}
