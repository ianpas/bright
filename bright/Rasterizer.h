#pragma once
#include "IRasterizer.h"

namespace pasha
{
	class Triangle
	{
	public:
		PipelineManager::VSOutput m_V1;
		PipelineManager::VSOutput m_V2;
		PipelineManager::VSOutput m_V3;
	};

	class Rasterizer : public IRasterizer
	{
	private:
		std::vector<Triangle> m_Triangles;

	private:
		class Interpolator
		{
		public:
			static void Interpolate(Triangle const& triangle);
		};

	public:
		Rasterizer();

		void Rasterize() override;

	private:
		void AssembleInput();
		void Clip();
		void PerspectiveDivide();
		void CullBackface();
		void ViewportTransform();
		void Interpolate();
	};

}
