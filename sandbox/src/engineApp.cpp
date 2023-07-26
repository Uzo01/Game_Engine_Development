/** \file engineApp.cpp
*/
#include "engineApp.h"
#include "sceneLayer.h"

engineApp::engineApp()
{
	std::shared_ptr<Engine::Layer> sceneLayer(new SceneLayer);
	m_layerStack.push(sceneLayer);
}

engineApp::~engineApp()
{

}

Engine::Application* Engine::startApplication()
{
	return new engineApp();
}