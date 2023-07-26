
#pragma once
#include "engine.h"
#include <fstream>
#include <entt/entt.hpp>
#include <glm/glm.hpp>

namespace MapLoader
{
	
	std::shared_ptr<IMAT3905::Texture> road_0tex;
	std::shared_ptr<IMAT3905::Texture> road_1tex;
	std::shared_ptr<IMAT3905::Texture> road_2tex;
	std::shared_ptr<IMAT3905::Texture> road_3tex;
	std::shared_ptr<IMAT3905::Texture> road_4tex;
	std::shared_ptr<IMAT3905::Texture> road_5tex;
	std::shared_ptr<IMAT3905::Texture> road_6tex;
	std::shared_ptr<IMAT3905::Texture> road_7tex;
	std::shared_ptr<IMAT3905::Texture> road_8tex;
	std::shared_ptr<IMAT3905::Texture> road_9tex;
	std::shared_ptr<IMAT3905::Texture> road_Atex;
	std::shared_ptr<IMAT3905::Texture> road_Btex;
	std::shared_ptr<IMAT3905::Texture> road_Ctex;
	std::shared_ptr<IMAT3905::Texture> Grass_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassDown_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassUp_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassLeft_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassRight_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassTLC_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassTRC_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassBLC_tex;
	std::shared_ptr<IMAT3905::Texture> pavGrassBRC_tex;
	std::shared_ptr<IMAT3905::Texture> pav_tex;
	std::shared_ptr<IMAT3905::Texture> water_tex;



	bool loadText(std::vector<entt::entity>& entities, std::string filepath, entt::registry& mReg)
	{
		//Roads
		road_0tex.reset(new IMAT3905::Texture("./assets/textures/Road_0.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_0subtex(new IMAT3905::SubTexture(*road_0tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_1tex.reset(new IMAT3905::Texture("./assets/textures/Road_1.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_1subtex(new IMAT3905::SubTexture(*road_1tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_2tex.reset(new IMAT3905::Texture("./assets/textures/Road_2.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_2subtex(new IMAT3905::SubTexture(*road_2tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_3tex.reset(new IMAT3905::Texture("./assets/textures/Road_3.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_3subtex(new IMAT3905::SubTexture(*road_3tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_4tex.reset(new IMAT3905::Texture("./assets/textures/Road_4.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_4subtex(new IMAT3905::SubTexture(*road_4tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_5tex.reset(new IMAT3905::Texture("./assets/textures/Road_5.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_5subtex(new IMAT3905::SubTexture(*road_5tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_6tex.reset(new IMAT3905::Texture("./assets/textures/Road_6.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_6subtex(new IMAT3905::SubTexture(*road_6tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_7tex.reset(new IMAT3905::Texture("./assets/textures/Road_7.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_7subtex(new IMAT3905::SubTexture(*road_7tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_8tex.reset(new IMAT3905::Texture("./assets/textures/Road_8.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_8subtex(new IMAT3905::SubTexture(*road_8tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_9tex.reset(new IMAT3905::Texture("./assets/textures/Road_9.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_9subtex(new IMAT3905::SubTexture(*road_9tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_Atex.reset(new IMAT3905::Texture("./assets/textures/Road_A.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_Asubtex(new IMAT3905::SubTexture(*road_Atex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_Btex.reset(new IMAT3905::Texture("./assets/textures/Road_B.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_Bsubtex(new IMAT3905::SubTexture(*road_Btex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		road_Ctex.reset(new IMAT3905::Texture("./assets/textures/Road_C.png"));
		std::shared_ptr<IMAT3905::SubTexture> road_Csubtex(new IMAT3905::SubTexture(*road_Ctex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		Grass_tex.reset(new IMAT3905::Texture("./assets/textures/Grass.png"));
		std::shared_ptr<IMAT3905::SubTexture> grass_subtex(new IMAT3905::SubTexture(*Grass_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassDown_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassDown.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassD_subtex(new IMAT3905::SubTexture(*pavGrassDown_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassUp_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassUp.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassU_subtex(new IMAT3905::SubTexture(*pavGrassUp_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassLeft_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassLeft.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassL_subtex(new IMAT3905::SubTexture(*pavGrassLeft_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassRight_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassRight.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassR_subtex(new IMAT3905::SubTexture(*pavGrassRight_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));

		pavGrassTLC_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassTopLeftCorner.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassTLC_subtex(new IMAT3905::SubTexture(*pavGrassTLC_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassTRC_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassTopRightCorner.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassTRC_subtex(new IMAT3905::SubTexture(*pavGrassTRC_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassBLC_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassBottomLeftCorner.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassBRC_subtex(new IMAT3905::SubTexture(*pavGrassBLC_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		pavGrassBRC_tex.reset(new IMAT3905::Texture("./assets/textures/PavementGrassBottomRightCorner.png"));
		std::shared_ptr<IMAT3905::SubTexture> pavgrassBLC_subtex(new IMAT3905::SubTexture(*pavGrassBRC_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));
		water_tex.reset(new IMAT3905::Texture("./assets/textures/WaterPavementUp.png"));
		std::shared_ptr<IMAT3905::SubTexture> water_subtex(new IMAT3905::SubTexture(*water_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));

		pav_tex.reset(new IMAT3905::Texture("./assets/textures/Pavement.png"));
		std::shared_ptr<IMAT3905::SubTexture> pav_subtex(new IMAT3905::SubTexture(*pav_tex.get(), glm::vec2(0.f), glm::vec2(1.f)));

		std::string line;
		glm::vec2 pos(-100.f, -100.f);

		// Read from the text file
		std::ifstream file(filepath.c_str());
		if (!file.is_open()) { return false; }

		// Use a while loop together with the getline() function to read the file line by line
		while (getline(file, line)) {
			// Output the text from the file
			pos.x = -100.f;
			for (auto ch : line)
			{
				switch (ch)
				{
				case 'w':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), glm::vec4(0.1,0.35, 0.8 ,1.0f));
					break;
				}
				case 'p':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), glm::vec4(0.1, 0.35, 0.8, 1.0f));
					break;
				}
				case '0':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_0subtex);
					break;
				}
				case '1':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_1subtex);
					break;
				}
				case '2':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_2subtex);
					break;
				}
				case '3':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_3subtex);
					break;
				}
				case '4':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_4subtex);
					break;
				}
				case '5':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_5subtex);
					break;
				}
				case '6':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_6subtex);
					break;
				}
				case '7':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_7subtex);
					break;
				}
				case '8':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_8subtex);
					break;
				}
				case '9':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_9subtex);
					break;
				}
				case 'A':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_Asubtex);
					break;
				}
				case 'B':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_Bsubtex);
					break;
				}

				case 'C':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), road_Csubtex);
					break;
				}
				case 'G':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), grass_subtex);
					break;
				}
				case 'g':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassD_subtex);
					break;
				}
				case 'U':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassU_subtex);
					break;
				}
				case 'L':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassL_subtex);
					break;
				}
				case 'R':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassR_subtex);
					break;
				}
				case 'T':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassTLC_subtex);
					break;
				}
				case 't':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassTRC_subtex);
					break;
				}
				case 'D':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassBLC_subtex);
					break;
				}
				case 'd':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pavgrassBRC_subtex);
					break;
				}
				case 'P':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), pav_subtex);
					break;
				}
				case 'O':
				{
					entities.push_back(mReg.create());
					mReg.emplace<Engine::TransformComponent>(entities.back(), pos, 0.f);
					mReg.emplace<Engine::RenderComponent>(entities.back(), glm::vec2(2.5f, 2.5f), water_subtex);
					break;
				}
				
				case '-': break;
				default: break;
				}
			
				pos.x += 5.f;
			}
			pos.y += 5.f;
		}

		// Close the file
		file.close();
		return true;
	}
}
