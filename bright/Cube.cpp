#include "stdafx.h"
#include "Cube.h"
#include "Renderer.h"
#include "CubeMesh.h"
#include "VertexShader.h"
#include "Transform.h"
#include "Camera.h"

namespace pasha
{
	Cube::Cube()
	{
		Awake();
	}

	void Cube::Awake()
	{
		AddComponent<Transform>(this);
		AddComponent<Camera>(this);
		AddComponent<CubeMesh>(this);
		AddComponent<Renderer>(this);
		AddComponent<VertexShader>(this);

	}

	void Cube::Update()
	{
		
	}

	void Cube::Render()
	{
		Update();

		auto& renderer = GetComponent<IRenderer>();
		renderer.Render();
	}
}