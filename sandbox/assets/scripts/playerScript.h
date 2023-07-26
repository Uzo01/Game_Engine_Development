/**\file playerScript.h*/
#pragma once
#include "engine.h"
#include "GLFW/glfw3.h"


class PlayerScript : public Engine::NativeScript
{
public:
	PlayerScript(entt::entity ent) : Engine::NativeScript(ent) {}
	void onUpdate(float timestep) override
	{
		auto& rbc = m_reg.get<Engine::RigidbodyComponent>(m_ent);
		desVel = glm::vec2(0.f);
		float desAngVel = 0.f;
		float theta = rbc.body->GetAngle();

		if (Engine::InputPoller::isKeyPressed(GLFW_KEY_A))// Left
		{
			desVel += glm::vec2(cosf(theta) * -speed, sinf(theta) * -speed);
		}

		if (Engine::InputPoller::isKeyPressed(GLFW_KEY_D))// Right
		{
			desVel += glm::vec2(cosf(theta) * speed, sinf(theta) * speed);
		}

		if (Engine::InputPoller::isKeyPressed(GLFW_KEY_W)) //Up 
		{
			desVel += glm::vec2(-sinf(theta) * -speed, cosf(theta) * -speed);
		}
		if (Engine::InputPoller::isKeyPressed(GLFW_KEY_S))// Down
		{
			desVel += glm::vec2(-sinf(theta) * speed, cosf(theta) * speed);
		}
		if (Engine::InputPoller::isKeyPressed(GLFW_KEY_Q))
		{
			desAngVel += angVel;
		}
		if (Engine::InputPoller::isKeyPressed(GLFW_KEY_E))
		{
			desAngVel -= angVel;
		}
		glm::vec2 deltVel;
		glm::vec2 currVel;
		
	

		currVel.x = rbc.body->GetLinearVelocity().x;
		currVel.y = rbc.body->GetLinearVelocity().y;
		

		deltVel = desVel - currVel;
		glm::vec2 force;

		force =(deltVel / timestep)* rbc.body->GetMass();

		rbc.body->ApplyForceToCenter(b2Vec2(force.x, force.y), true);

		
		float deltaAngVel;
		float currAngVel = rbc.body->GetAngularVelocity();

		deltaAngVel = desAngVel - currAngVel;
		float torque;

		torque = (deltaAngVel / timestep) * rbc.body->GetInertia();

		rbc.body->ApplyTorque(torque, true);

		

	}
	void onKeyPressed(Engine::KeyPressedEvent& e) override{};
private: 
	glm::vec2 desVel = glm::vec2(0.f);
	float speed = 6.5f;

	float angVel = 1.f;

};
// angle 

