#pragma once
#include <vector>
#include "MeshType.h"

namespace pasha
{
	class IMeshManager
	{
	public:
		virtual ~IMeshManager() = default;

	public:
		void						virtual ImportMesh(std::string const& mesh_path) = 0;

		std::vector<Vertex>			virtual GetVertices() const = 0;
		std::vector<unsigned int>   virtual GetIndices() const = 0;
	};
}