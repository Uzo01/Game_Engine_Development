/**\file tranformComp.h*/

#pragma once

#include <glm/glm.hpp>

namespace Engine

{
	class TransformComponent
	{
	public:
		glm::vec2 position;
		float angle;
		TransformComponent(glm::vec2 pos, float ang) { position = pos; angle = ang; }
	};
}