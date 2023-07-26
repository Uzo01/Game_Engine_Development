/**\file layerStack.h*/
#pragma once

#include <vector>
#include "independent/core/layer.h"
namespace Engine
{
	/**\ 
	* Layerstack draws in order
	* Drawn back to front 
	* Handle events in order front to back
	*/
	class LayerStack
	{
	public:
		void push(const std::shared_ptr<Layer>& layer);//!< push constructor take const ref to shared pointer in layer
		void pop();//!< pop constructor
		void onUpdate(float timestep); //!< onUpdate coonstructor
		void onRender(); //!< onRender constructor
		void onKeyPress(KeyPressedEvent& e); //!< keyPressed events constructor
	private:
		std::vector<std::shared_ptr<Layer>> m_stack; //!< stack of layers in a vector 

	};
}