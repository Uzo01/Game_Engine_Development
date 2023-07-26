/**\file layer.h*/
#pragma once
#include "events/windowEvents.h"
namespace Engine
{
	/**\
	* Layer a rendered scene
	* Rasterised for 2d rendering 
	* Push the layers onto the layerstack
	*/
	class Layer
	{
	public:
	virtual	void onAttach() = 0; //!< attach constructor
	virtual	void onDetach() = 0; //!< Detach constructor
	virtual	void onUpdate(float timestep) = 0; //!< onUpdate constructor 
	virtual	void onRender() = 0; //!< Render constructor
	virtual	void onKeyPressed(KeyPressedEvent& e) = 0; //!< keyPressed events constructor

	};
}