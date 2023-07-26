/**\ file menuLayer.h */
#pragma once

#include "engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Engine;

class MenuLayer : public Layer
{
public:
	MenuLayer(); //!<Constructor
	void onRender() override;

	virtual void onKeyPress(KeyPressedEvent& e); //!< onKey pressed event constructor
	virtual void onMouseMove(MouseMovedEvent& e);//!< onMouseMoved Event constructor
	virtual void onMousePress(ButtonPressedEvent& e);//!< onButton pressed event constructor
	virtual void onMouseRelease(ButtonReleasedEvent& e);
private :
	glm::mat4 view, projection; //!< view and project matri
	//GetSysModalWindow ModalWindow;
};