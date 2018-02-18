#pragma once
#include "GameObject.h"


namespace pasha
{
	class Cube :public GameObject
	{
	public:
		Cube();

	public:
		void							Render() override;

	private:
		void							Awake() override; 
		void							Update() override;


	};
}