/** \file rigidbody.h
*/
#pragma once

#include "engine.h"
#include "glm/glm.hpp"
#include "box2d/box2d.h"
#include <entt/entt.hpp>


 namespace Engine
{
	class RigidbodyComponent
	{
	public:
		RigidbodyComponent(entt::entity entity, float restitution, b2BodyType type, glm::vec4 p_colour)
		{
			auto& tc = Application::getInstance().m_reg.get<TransformComponent>(entity);
			auto world = Application::getInstance().physicsWorld;
			b2BodyDef rigidBodyDef;
			rigidBodyDef.type = type;
			rigidBodyDef.position = b2Vec2(tc.position.x, tc.position.y);
			rigidBodyDef.angle = tc.angle;
			body = world->CreateBody(&rigidBodyDef);
			body->GetUserData().pointer = entt::to_integral(entity);
			colour = p_colour;
		}
		b2Body* body;
		glm::vec4 colour;
	};

	class BoxCollider
	{
	public:
		BoxCollider(entt::entity entity, const glm::vec2& halfExtents)
		{
			auto& rbc = Application::getInstance().m_reg.get<RigidbodyComponent>(entity);
			shape.SetAsBox(halfExtents.x, halfExtents.y);

			b2FixtureDef colliderDef;
			colliderDef.shape = &shape;
			colliderDef.density = 1.f;
			rbc.body->CreateFixture(&colliderDef);
		}
		b2PolygonShape shape;
		b2Fixture* collider;
		
	};
}

