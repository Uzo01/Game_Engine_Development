#pragma once
#include "engine.h"
#include <memory>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class SceneLayer : public Engine::Layer
{
public:
	SceneLayer() : mReg(Engine::Application::getInstance().m_reg) {}
	void onAttach(); //!< attach constructor
	void onDetach(); //!< Detach constructor
	void onUpdate(float timestep); //!< onUpdate constructor 
	void onRender(); //!< Render constructor
	void onKeyPressed(Engine::KeyPressedEvent& e);
private:
	//!<Texture
	std::shared_ptr<IMAT3905::Texture> techBGtex;
	std::shared_ptr<IMAT3905::Texture> playertex;
	std::shared_ptr<IMAT3905::Texture> roadstex;
	std::shared_ptr<IMAT3905::Texture> house_1Tex;
	std::shared_ptr<IMAT3905::Texture> house_2Tex;
	std::shared_ptr<IMAT3905::Texture> house_3Tex;
	std::shared_ptr<IMAT3905::Texture> house_4Tex;
	std::shared_ptr<IMAT3905::Texture> def;

	//!<SubTexture
	std::shared_ptr<IMAT3905::SubTexture> playersubtex;
	std::shared_ptr<IMAT3905::SubTexture> techBGsubtex;
	std::shared_ptr<IMAT3905::SubTexture> roadssubtex;
	std::shared_ptr<IMAT3905::SubTexture> house_1subtex;
	std::shared_ptr<IMAT3905::SubTexture> house_2subtex;
	std::shared_ptr<IMAT3905::SubTexture> house_3subtex;
	std::shared_ptr<IMAT3905::SubTexture> house_4subtex;
	std::shared_ptr<IMAT3905::SubTexture> defsub;


	entt::registry& mReg;
	//!<Entity
	std::vector<entt::entity> mapEntities;
	entt::entity house[14];
	entt::entity player;
	entt::entity RedNPC;
	entt::entity techBG;
	entt::entity camera;
	std::vector<entt::entity> NPCs;
	
	
};