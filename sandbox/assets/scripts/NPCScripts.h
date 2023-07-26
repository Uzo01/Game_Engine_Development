/**\file NPCScripts.h*/
#pragma once
#include "engine.h"
#include "GLFW/glfw3.h"


class NPCScript : public Engine::NativeScript
{
public:
	NPCScript(entt::entity ent, const std::vector<glm::vec2>& path, const std::vector<float>& tSpeeds, float t, size_t index, glm::vec4 colour) : 
		Engine::NativeScript(ent),
		m_path(path),
		m_tSpeeds(tSpeeds),
		m_index(index),
		m_t(t)
	{
		m_reg.emplace<Engine::TransformComponent>(ent, calcPos(), 0.f);
		m_reg.emplace<Engine::RenderComponent>(ent, glm::vec2(1.0, 1.0), colour);
		m_reg.emplace<Engine::RigidbodyComponent>(ent, ent, 0.5f, b2BodyType::b2_kinematicBody, glm::vec4(1.f));
		m_reg.emplace<Engine::BoxCollider>(ent, ent, glm::vec2(0.5, 0.5));
	}
	
	void onUpdate(float timestep) override
	{
		if (m_zombie)
		{
			// NEEDS WORK
		}
		else
		{
			m_t += m_tSpeeds[m_index] * timestep;
			if (m_t > 1.0f)
			{
				m_t -= 1.0f;
				m_index++;
				if (m_index >= m_path.size()) m_index = 0;
			}

			glm::vec2 pos = calcPos();
			auto& rbc = m_reg.get<Engine::RigidbodyComponent>(m_ent);
			rbc.body->SetTransform(b2Vec2(pos.x, pos.y), 0.f);
		}
	}
	void onKeyPressed(Engine::KeyPressedEvent& e) override {};
private:
	std::vector<glm::vec2> m_path;
	std::vector<float> m_tSpeeds;
	float m_t;
	size_t m_index;
	bool m_zombie = false;

	glm::vec2 calcPos()
	{
		glm::vec2 a = m_path[m_index];
		glm::vec2 b = m_path[(m_index + 1) % m_path.size()];
		glm::vec2 pos = (a * (1.f - m_t)) + (b * m_t);
		return pos;
	}
};
