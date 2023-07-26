/**\ file orthographicCameraComp*/
#pragma once

#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>


namespace Engine
{
	struct OrthographicCamProps
	{
		float left = 0.f;
		float top = 0.f;
		float right = 800.f;
		float bottom = 600.f;
	
	};
	class OrthographicCamComp
	{
	public:
		OrthographicCamComp(OrthographicCamProps p) 
		{
			settings = p; //!< Orthographic camera properties
			glm::mat4 pos(1.0f);//!< identiy mat
			viewMat = glm::inverse(pos);//!< view mat
			projectionMat = glm::ortho(settings.left, settings.right, settings.bottom, settings.top); //!< orthographic components
		};
		glm::mat4 projectionMat; //!< projection matrix
		glm::mat4 viewMat; //!< view matrix
	

		OrthographicCamProps settings;
	};
}