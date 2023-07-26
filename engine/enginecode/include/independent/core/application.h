/** \file application.h
*/
#pragma once

#include "systems/log.h"
#include "core/timer.h"
#include "events/event.h"
#include "events/windowEvents.h"
#include "events/eventHandler.h"
#include "core/window.h"
#include "camera/cameraControllerEuler.h"
#include "inputPoller.h"
#include "core/layerStack.h"
#include "entt/entt.hpp"
#include "box2d/box2d.h"
namespace Engine {

	/**
	\class Application
	Fundemental class of the engine. A singleton which runs the game loop infinitely.
	Provides ...
	*/

	class Application
	{
	protected:
		Application(); //!< Constructor

		std::shared_ptr<Log> m_logSysem;//!< logging system
		std::shared_ptr<System> m_windowSystem; //!< Window system
		
		std::shared_ptr<Window> m_window; //!< window
		std::shared_ptr<Timer> m_timer; //!< Timer
	
		LayerStack m_layerStack;
	
		

		bool onClose(WindowCloseEvents& e); //!< Run when window is closed 
		bool onResize(WindowResizeEvent& e); 
		bool onMouseButtonPressed(ButtonPressedEvent& e);

	private:
		static Application* s_instance; //!< Singleton instance of the application
		bool m_running = true; //!< Is the application running?
	
	public:
		virtual ~Application(); //!< Deconstructor
		inline static Application& getInstance() { return *s_instance; } //!< Instance getter from singleton pattern
		void run(); //!< Main loop
		std::shared_ptr<Window> getWindow() { return m_window; };
		entt::registry m_reg;
		b2World* physicsWorld = nullptr;

	};

	// To be defined in users code
	Application* startApplication(); //!< Function definition which provides an entry hook
}