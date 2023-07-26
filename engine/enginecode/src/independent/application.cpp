/** \file application.cpp
*/

#include "engine_pch.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "core/application.h"
#ifdef NG_PLATFORM_WINDOWS
#include "platform/windows/WinTimer.h"
#endif // NG_PLATFORM_WINDOWS
#ifdef NG_PLATFORM_WINDOWS
#include "platform/GLFWSystem/GLFWSystem.h"
#endif // NG_PLATFORM_WINDOWS
#include "platform/OpenGL/OpenGLVertexArray.h"


#include "renderer2D.h"
#include "platform/OpenGL/OpenGLShader.h"
#ifdef NG_PLATFORM_WINDOWS
#include "platform/OpenGL/OpenGLTexture.h"
#endif // NG_PLATFORM_WINDOWS
namespace Engine {
	// Set static vars
	Application* Application::s_instance = nullptr;

	Application::Application()
	{
		if (s_instance == nullptr)
		{
			s_instance = this;
		}

		// Start system

		// Start log
		m_logSysem.reset(new Log); //!<Initilise log system
		m_logSysem->start();


#ifdef NG_PLATFORM_WINDOWS
		//start window system
		m_windowSystem.reset(new GLFWSystem); //!<rest the window system
#endif

		m_windowSystem->start(); //!< start window system


		//Reset the timer
#ifdef NG_PLATFORM_WINDOWS
		m_timer.reset(new WinTimer); //!<Initilise timer system
#else
		m_timer.reset(new ChronoTimer);
#endif
		m_timer->start();

		m_window.reset(Window::create());

		m_window->getEventHandler().setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));
		m_window->getEventHandler().setOnResizeCallback(std::bind(&Application::onResize, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMoseButtonPressedCallback(std::bind(&Application::onMouseButtonPressed, this, std::placeholders::_1));



		InputPoller::setCurrentWindow(m_window->getNativeWindow());
		

		IMAT3905::Renderer2D::init(
			m_window->getWidth(),       // Window width
			m_window->getHeight(),      // Window height
			800000,                      // Batch size i.e. 20000 things rendered in one batch
			"./assets/fonts/arial.ttf", // Font file location
			64                          // Character size to load font
		);

		physicsWorld = new b2World(b2Vec2(0.0f, 0.0f));

		IMAT3905::Renderer2D::setClearColour({ 1.f,0.f,1.f,1.f });
		m_timer->reset();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	bool Application::onClose(WindowCloseEvents& e)//!< binding tool use for handler
	{
		e.handle(true);
		m_running = false;
		return e.handled();
	}

	bool Application::onResize(WindowResizeEvent& e)
	{
		m_window->onResize(e.getSize());
		IMAT3905::Renderer2D::onResize(e.getSize());
		e.handle(true);
		return e.handled();
	}

	bool Application::onMouseButtonPressed(ButtonPressedEvent& e)
	{
		auto id = IMAT3905::Renderer2D::getID(InputPoller::getMousePosition());
		Log::info("Entity ID: {0}", id);
		e.handle(true);
		return e.handled();
	}

	Application::~Application()
	{

		// Stop System

		// Stop Logger
		m_logSysem->stop();
		//!<Stop window system
		m_windowSystem->stop();
	}



	void Application::run()
	{
		/*
		IMAT3905::Texture numbers("./assets/textures/numberCube.png");
		IMAT3905::Texture letters("./assets/textures/letterCube.png");
		IMAT3905::Texture moon("./assets/textures/moon.png");
		IMAT3905::SubTexture five(numbers, glm::vec2(0.33f, 0.5f), glm::vec2(0.66f, 1.0f));
		IMAT3905::SubTexture e(letters, glm::ivec2(100, 100), glm::ivec2(200, 200));
		IMAT3905::SubTexture m(moon, glm::ivec2(100, 100), glm::ivec2(5, 5));

		glEnable(GL_DEPTH_TEST);
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

		glm::mat4 view = glm::mat4(1.f);
		glm::mat4 proj = glm::ortho(0.f, m_window->getWidthf(), m_window->getHeightf(), 0.f);
		*/

		float timestep = 0.f;

		while (m_running)
		{
			timestep = m_timer->getElapsedTime();
			m_timer->reset();
			
			m_layerStack.onUpdate(timestep);
			m_layerStack.onRender();
			/*
			IMAT3905::Renderer2D::begin(view, proj);

			IMAT3905::Renderer2D::submit({ 512,400 }, 0.f, { 50,25 }, glm::vec4(1.f), 0);
			IMAT3905::Renderer2D::submit({ 150,100 }, 0.f, { 100,75 }, numbers, 1);
			IMAT3905::Renderer2D::submit({ 300,250 }, 0.f, { 100,75 }, letters, 2);
			IMAT3905::Renderer2D::submit({ 100,400 }, 0.f, { 100,75 }, moon, 3);
			IMAT3905::Renderer2D::submit({ 512,100 }, 30.f, { 90,25 }, glm::vec4(1.f, 0, 0, 1), 3, true);
			IMAT3905::Renderer2D::submit({ 250,500 }, glfwGetTime() * 15.f, { 60,60 }, five, 4, true);
			IMAT3905::Renderer2D::submit({ 600,250 }, glfwGetTime() * -25.f, { 75,75 }, e, 5, true);
			IMAT3905::Renderer2D::submit("Hello", { 300,200 }, glm::vec4(1.f));

			IMAT3905::Renderer2D::end();
			*/

			m_window->onUpdate(timestep);
		};
		//IMAT3905::Renderer2D::terminate();

	
	}

}
