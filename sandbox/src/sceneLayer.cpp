#include "sceneLayer.h"
#include "playerScript.h"
#include "NPCScripts.h"
#include "mapLoader.h"
using namespace Engine;

void SceneLayer::onAttach()
{
	//TechBG
	techBGtex.reset(new IMAT3905::Texture("./assets/textures/techBG.png"));
	techBGsubtex.reset(new IMAT3905::SubTexture(*techBGtex.get(), glm::vec2(0.f), glm::vec2(1.f)));
	IMAT3905::Renderer2D::setClearColour(glm::vec4(0.f));

	if (!MapLoader::loadText(mapEntities, "./assets/maps/map_01.txt", mReg))
	{
		// FAIL
	}// Aghrr!

	//Player
	playertex.reset(new IMAT3905::Texture("./assets/textures/numberCube.png"));
	playersubtex.reset(new IMAT3905::SubTexture(*playertex.get(), glm::vec2(0.f, 0.f), glm::vec2(1.0f, 1.0f)));
	// Building
	house_1Tex.reset(new IMAT3905::Texture("./assets/textures/Building1.png"));
	house_1subtex.reset(new IMAT3905::SubTexture(*house_1Tex.get(), glm::vec2(0.f, 0.f), glm::vec2(1.0f, 1.0f)));
	// building 2
	house_2Tex.reset(new IMAT3905::Texture("./assets/textures/Building2.png"));
	house_2subtex.reset(new IMAT3905::SubTexture(*house_2Tex.get(), glm::vec2(0.f, 0.f), glm::vec2(1.0f, 1.0f)));
	// Building 3
	house_3Tex.reset(new IMAT3905::Texture("./assets/textures/Building3.png"));
	house_3subtex.reset(new IMAT3905::SubTexture(*house_3Tex.get(), glm::vec2(0.f, 0.f), glm::vec2(1.0f, 1.0f)));
	// Building 4
	house_4Tex.reset(new IMAT3905::Texture("./assets/textures/Building4.png"));
	house_4subtex.reset(new IMAT3905::SubTexture(*house_4Tex.get(), glm::vec2(0.f, 0.f), glm::vec2(1.0f, 1.0f)));
	
	unsigned char px[4] = { 255, 255, 255, 128 };
	def.reset(new IMAT3905::Texture(1, 1, 4, px));
	defsub.reset(new IMAT3905::SubTexture(*def.get(), glm::vec2(0.f, 0.f), glm::vec2(1.0f, 1.0f)));
	
	//Camera
	camera = mReg.create();
	mReg.emplace<TransformComponent>(camera, glm::vec2(0, 0), 0.f);
	OrthographicCamProps camProps;



	camProps.left = -150.f;
	camProps.right = 150.f;
	camProps.top = -150.f;
	camProps.bottom = 150.f;
	mReg.emplace<OrthographicCamComp>(camera, camProps);

	//auto win = Application::getInstance().getWindow();

	//House
	house[0] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[0], glm::vec2(75.0, -20.00), 0.f);
	mReg.emplace<RenderComponent>(house[0], glm::vec2(15.50, 10.00), house_1subtex);
	mReg.emplace<RigidbodyComponent>(house[0], house[0], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[0], house[0], glm::vec2(15.50, 10.00));

	house[1] = mReg.create();
	mReg.emplace<TransformComponent>(house[1], glm::vec2(-65, -40.00), 0.f);
	mReg.emplace<RenderComponent>(house[1], glm::vec2(15.50, 10.00), house_2subtex);
	mReg.emplace<RigidbodyComponent>(house[1], house[1], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[1], house[1], glm::vec2(15.50, 10.00));

	house[2] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[2], glm::vec2(-65.0, 10.00), 0.f);
	mReg.emplace<RenderComponent>(house[2], glm::vec2(15.50, 10.00), house_3subtex);
	mReg.emplace<RigidbodyComponent>(house[2], house[2], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[2], house[2], glm::vec2(15.50, 11.00));

	house[3] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[3], glm::vec2(-25, -20), 0.f);
	mReg.emplace<RenderComponent>(house[3], glm::vec2(15.50, 10.00), house_2subtex);
	mReg.emplace<RigidbodyComponent>(house[3], house[3], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[3], house[3], glm::vec2(15.50, 10.00));

	house[4] = mReg.create();
	mReg.emplace<TransformComponent>(house[4], glm::vec2(-5, 30), 0.f);
	mReg.emplace<RenderComponent>(house[4], glm::vec2(15.50, 10.00), house_1subtex);
	mReg.emplace<RigidbodyComponent>(house[4], house[4], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[4], house[4], glm::vec2(15.50, 10.00));

	house[5] = mReg.create();//Done
	mReg.emplace<TransformComponent>(house[5], glm::vec2(11.0, 72.0), 0.f);
	mReg.emplace<RenderComponent>(house[5], glm::vec2(15.50, 10.00), house_4subtex);
	mReg.emplace<RigidbodyComponent>(house[5], house[5], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[5], house[5], glm::vec2(15.50, 10.00));

	house[6] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[6], glm::vec2(75.0, 20.00), 9.43f);
	mReg.emplace<RenderComponent>(house[6], glm::vec2(15.50, 10.00), house_3subtex);
	mReg.emplace<RigidbodyComponent>(house[6], house[6], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[6], house[6], glm::vec2(15.50, 10.00));

	house[7] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[7], glm::vec2(5, -40), 1.56f);
	mReg.emplace<RenderComponent>(house[7], glm::vec2(15.50, 10.00), house_2subtex);
	mReg.emplace<RigidbodyComponent>(house[7], house[7], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[7], house[7], glm::vec2(15.50, 10.00));

	house[8] = mReg.create();//Done
	mReg.emplace<TransformComponent>(house[8], glm::vec2(-60.0, 40.00), 1.56f);
	mReg.emplace<RenderComponent>(house[8], glm::vec2(15.50, 10.00), house_4subtex);
	mReg.emplace<RigidbodyComponent>(house[8], house[8], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[8], house[8], glm::vec2(15.50, 10.00));

	house[9] = mReg.create();
	mReg.emplace<TransformComponent>(house[9], glm::vec2(40, -26), 1.56f);
	mReg.emplace<RenderComponent>(house[9], glm::vec2(15.50, 10.00), house_1subtex);
	mReg.emplace<RigidbodyComponent>(house[9], house[9], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[9], house[9], glm::vec2(15.50, 10.00));

	house[10] = mReg.create();//Done
	mReg.emplace<TransformComponent>(house[10], glm::vec2(35.0, 21.50), 0.f);
	mReg.emplace<RenderComponent>(house[10], glm::vec2(15.50, 10.00), house_4subtex);
	mReg.emplace<RigidbodyComponent>(house[10], house[10], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[10], house[10], glm::vec2(15.50, 10.00));

	house[11] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[11], glm::vec2(-25, 65), 1.56f);
	mReg.emplace<RenderComponent>(house[11], glm::vec2(15.50, 10.00), house_2subtex);
	mReg.emplace<RigidbodyComponent>(house[11], house[11], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[11], house[11], glm::vec2(15.50, 10.00));

	house[12] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[12], glm::vec2(47.0, -57.0), 9.43f);
	mReg.emplace<RenderComponent>(house[12], glm::vec2(15.50, 10.00), house_3subtex);
	mReg.emplace<RigidbodyComponent>(house[12], house[12], 20.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[12], house[12], glm::vec2(15.50, 11.00));

	house[13] = mReg.create(); //Done
	mReg.emplace<TransformComponent>(house[13], glm::vec2(50, 55), 0.f);
	mReg.emplace<RenderComponent>(house[13], glm::vec2(15.50, 10.00), house_2subtex);
	mReg.emplace<RigidbodyComponent>(house[13], house[13], 10.0f, b2BodyType::b2_staticBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(house[13], house[13], glm::vec2(15.50, 10.00));
	
	//Player 
	player = mReg.create();
	mReg.emplace<TransformComponent>(player, glm::vec2(10.50, 10.00), 0.f);
	mReg.emplace<RenderComponent>(player, glm::vec2(5.0, 1.0), playersubtex);
	mReg.emplace<RigidbodyComponent>(player, player, 0.5f, b2BodyType::b2_dynamicBody, glm::vec4(1.f, 0.f, 0.f, 0.5f));
	mReg.emplace<BoxCollider>(player, player, glm::vec2(1.00, 0.75));
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(player);
		nsc.create<PlayerScript>(player);
	}
	//TechBG
	techBG = mReg.create();
	mReg.emplace<TransformComponent>(techBG, glm::vec2(0.f,0.f), 0.f);
	mReg.emplace<RenderComponent>(techBG, glm::vec2(102.5,102.5), techBGsubtex);//Floor component
	//RED TRAIL
	float redSpeed = 5.f;
	std::vector<glm::vec2> redTrail;
	redTrail.push_back(glm::vec2(-90.50, -75.00));
	redTrail.push_back(glm::vec2(20.50, -75.00));
	redTrail.push_back(glm::vec2(20.50, 0.00));
	redTrail.push_back(glm::vec2(-45.50, 0.00));
	redTrail.push_back(glm::vec2(-45.50, 60.00));
	redTrail.push_back(glm::vec2(-75.50, 60.00));
	redTrail.push_back(glm::vec2(-75.50, 95.00));
	std::vector<float> redTrailTSpeeds;


	for (int i = 0; i < redTrail.size() - 1; i++)
	{
		float dist = glm::length(redTrail[i + 1] - redTrail[i]);
		float tSpeed = 1.0f / (dist / redSpeed);
		redTrailTSpeeds.push_back(tSpeed);
	}
	float dist = glm::length(redTrail[0] - redTrail[redTrail.size()-1]);
	float tSpeed = 1.0f / (dist / redSpeed);
	redTrailTSpeeds.push_back(tSpeed);
	
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), redTrail, redTrailTSpeeds, 0.5, 5, glm::vec4(1, 0, 0, 1));
	}
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), , glm::vec4(1, 0, 0, 1));
	}*/
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(20.50, 0.00), glm::vec4(1, 0, 0, 1));
	}*/
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-45.50, 0.00), glm::vec4(1, 0, 0, 1));
	}*/
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), , glm::vec4(1, 0, 0, 1));
	}*/
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-75.50, 60.00), glm::vec4(1, 0, 0, 1));
	}*/
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-75.50, 95.00), glm::vec4(1, 0, 0, 1));
	}*/
	// YELLOW TRAIL
	std::vector<glm::vec2> yellowTrail;
	yellowTrail.push_back(glm::vec2(-90.50, -78.00));
	yellowTrail.push_back(glm::vec2(20.50, -78.00));
	yellowTrail.push_back(glm::vec2(20.50, -60.00));
	yellowTrail.push_back(glm::vec2(-10.50, -60.00));
	yellowTrail.push_back(glm::vec2(-10.50, -35.00));
	yellowTrail.push_back(glm::vec2(-45.50, -35.00));
	yellowTrail.push_back(glm::vec2(-45.50, -25.00));
	yellowTrail.push_back(glm::vec2(-85.50, -25.00));
	yellowTrail.push_back(glm::vec2(-85.50, -5.00));
	yellowTrail.push_back(glm::vec2(-45.50, -5.00));
	yellowTrail.push_back(glm::vec2(-45.50, 65.00));
	yellowTrail.push_back(glm::vec2(-70.50, 65.00));
	yellowTrail.push_back(glm::vec2(-70.50, 95.00));

	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-90.50, -78.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(20.50, -78.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(20.50, -60.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-10.50, -60.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-10.50, -35.00), glm::vec4(1, 1, 0, 1));
	}
	
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-45.50, -35.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-45.50, -25.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-85.50, -25.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-85.50, -5.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-45.50, -5.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-45.50, 65.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-70.50, 65.00), glm::vec4(1, 1, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-70.50, 95.00), glm::vec4(1, 1, 0, 1));
	}*/
	//BLACK PATH 
	std::vector<glm::vec2> blackTrail;
	blackTrail.push_back(glm::vec2(-50.50, 85.00));
	blackTrail.push_back(glm::vec2(30.50, 85.00));
	blackTrail.push_back(glm::vec2(30.50, 40.00));
	blackTrail.push_back(glm::vec2(95.50, 40.00));
	blackTrail.push_back(glm::vec2(95.50, -90.00));
	blackTrail.push_back(glm::vec2(65.50, -90.00));
	blackTrail.push_back(glm::vec2(65.50, -98.00));
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-50.50, 85.00), glm::vec4(0, 0, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(30.50, 85.00), glm::vec4(0, 0, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(30.50, 40.00), glm::vec4(0, 0, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(95.50, 40.00), glm::vec4(0, 0, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(95.50, -90.00), glm::vec4(0, 0, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(65.50, -90.00), glm::vec4(0, 0, 0, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(65.50, -98.00), glm::vec4(0, 0, 0, 1));
	}*/
	//WHITE PATH
	std::vector<glm::vec2> whiteTrail;
	whiteTrail.push_back(glm::vec2(70.50, -85.00));
	whiteTrail.push_back(glm::vec2(70.50, -35.00));
	whiteTrail.push_back(glm::vec2(95.50, -35.00));
	whiteTrail.push_back(glm::vec2(95.50, 0.00));
	whiteTrail.push_back(glm::vec2(25.50, 0.00));
	whiteTrail.push_back(glm::vec2(15.50, 0.00));
	whiteTrail.push_back(glm::vec2(15.50, 45.00));
	whiteTrail.push_back(glm::vec2(-20.50, 45.00));
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(70.50, -85.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(70.50, -35.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(95.50, -35.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(95.50, 0.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(25.50, 0.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(15.50, 0.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(15.50, 45.00), glm::vec4(1, 1, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-20.50, 45.00), glm::vec4(1, 1, 1, 1));
	}*/
	//BLUE TRAIL
	std::vector<glm::vec2> blueTrail;
	blueTrail.push_back(glm::vec2(75.50, 55.00));
	blueTrail.push_back(glm::vec2(95.50, 55.00));
	blueTrail.push_back(glm::vec2(95.50, 75.00));
	blueTrail.push_back(glm::vec2(30.50, 75.00));
	blueTrail.push_back(glm::vec2(30.50, 85.00));
	blueTrail.push_back(glm::vec2(-80.50, 85.00));
	/*NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(75.50, 55.00), glm::vec4(0, 0, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(95.50, 55.00), glm::vec4(0, 0, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(95.50, 75.00), glm::vec4(0, 0, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(30.50, 75.00), glm::vec4(0, 0, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(30.50, 85.00), glm::vec4(0, 0, 1, 1));
	}
	NPCs.push_back(mReg.create());
	{
		auto& nsc = mReg.emplace<NativeScriptComponent>(NPCs.back());
		nsc.create<NPCScript>(NPCs.back(), glm::vec2(-80.50, 85.00), glm::vec4(0, 0, 1, 1));
	}*/
	

}

void SceneLayer::onDetach()
{

}

void SceneLayer::onUpdate(float timestep)
{
	Application::getInstance().physicsWorld->Step(timestep, 3, 5);

	auto nativeScriptView = mReg.view<NativeScriptComponent>();
	for (auto entity : nativeScriptView)
	{
		auto& nsc = mReg.get<NativeScriptComponent>(entity);

		nsc.onUpdate(timestep);
	}

	auto physicsView = mReg.view<TransformComponent, RigidbodyComponent>();
	for (auto entity : physicsView)
	{
		auto& tc = mReg.get<TransformComponent>(entity);
		auto& rbc = mReg.get<RigidbodyComponent>(entity);

		tc.angle = rbc.body->GetAngle();
		tc.position = glm::vec2(rbc.body->GetPosition().x, rbc.body->GetPosition().y);
		
	}
	auto playerView = mReg.view<TransformComponent>();
	for (auto player : playerView)
	{
		/*auto& */
	}
	
}//Hello

void SceneLayer::onRender()
{
	auto& cc = mReg.get<OrthographicCamComp>(camera);
	

	IMAT3905::Renderer2D::begin(cc.viewMat, cc.projectionMat);
	for (auto entity : mapEntities)
	{
		auto& tc = mReg.get<TransformComponent>(entity);
		auto& rc = mReg.get<RenderComponent>(entity);
		IMAT3905::Renderer2D::submit(tc.position, tc.angle, rc.halfExtents, *rc.subTexture, rc.tint, (int32_t)entt::to_integral(entity));
	}
	//IMAT3905::Renderer2D::end();

	//IMAT3905::Renderer2D::begin(cc.viewMat, cc.projectionMat);
	for (auto entity : house)
	{
		auto& tc = mReg.get<TransformComponent>(entity);
		auto& rc = mReg.get<RenderComponent>(entity);
		IMAT3905::Renderer2D::submit(tc.position, tc.angle, rc.halfExtents, *rc.subTexture, rc.tint, (int32_t)entt::to_integral(entity));
	}

	for (auto entity : NPCs)
	{
		auto& tc = mReg.get<TransformComponent>(entity);
		auto& rc = mReg.get<RenderComponent>(entity);
		IMAT3905::Renderer2D::submit(tc.position, tc.angle, rc.halfExtents, *rc.subTexture, rc.tint, (int32_t)entt::to_integral(entity));
	}

	auto& tc = mReg.get<TransformComponent>(player);
	auto& rc = mReg.get<RenderComponent>(player);
	IMAT3905::Renderer2D::submit(tc.position, tc.angle, rc.halfExtents, *rc.subTexture, rc.tint, (int32_t)entt::to_integral(player));

	auto& rbcView = mReg.view<RigidbodyComponent, BoxCollider>();
	for (auto entity : rbcView)
	{
		auto& rbc = mReg.get<RigidbodyComponent>(entity);
		auto& box = mReg.get<BoxCollider>(entity);
		auto& p = rbc.body->GetPosition();
		glm::vec2 pos(p.x, p.y);
		float ang = rbc.body->GetAngle();
		glm::vec2 he(0.f);
		for (int i = 0; i < box.shape.m_count; i++)
		{
			he.x = std::max(he.x, box.shape.m_vertices[i].x);
			he.y = std::max(he.y, box.shape.m_vertices[i].y);
		}


		IMAT3905::Renderer2D::submit(pos, ang, he, *defsub);
	}


	IMAT3905::Renderer2D::end();
}

void SceneLayer::onKeyPressed(Engine::KeyPressedEvent& e)
{

}
