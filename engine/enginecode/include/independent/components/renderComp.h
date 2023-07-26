/**\file renderComp.h*/

#pragma once

#include <glm/glm.hpp>
#include "renderer2D.h"

namespace Engine
{
	class RenderComponent
	{
	public:
		glm::vec2 halfExtents;
		glm::vec4 tint;
		std::shared_ptr<IMAT3905::SubTexture> subTexture;
		inline static std::shared_ptr<IMAT3905::Texture> defaultTexture = nullptr;
		RenderComponent(glm::vec2 halfExt, std::shared_ptr<IMAT3905::SubTexture> subTex)
		{ 
			subTexture = subTex;
			halfExtents = halfExt;
			tint = glm::vec4(1.f);
		}
		RenderComponent(glm::vec2 halfExt, glm::vec4 tin) 
		{ 
			tint = tin; 
			halfExtents = halfExt; 
			if (!defaultTexture)
			{
				unsigned char whitePx[4] = { 255,255,255,255 };
				defaultTexture.reset(new IMAT3905::Texture(1, 1, 4, whitePx));
			}
			subTexture.reset(new IMAT3905::SubTexture(*defaultTexture, glm::vec2(0.f), glm::vec2(1.f)));
		}
		RenderComponent(glm::vec2 halfExt, glm::vec4 tin, std::shared_ptr<IMAT3905::SubTexture> subTex) 
		{ 
			tint = tin; 
			subTexture = subTex; 
			halfExtents = halfExt; }
	};
}
