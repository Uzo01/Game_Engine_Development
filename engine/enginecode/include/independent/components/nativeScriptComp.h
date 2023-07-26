/**\ file nativeScriptComp.h */
#pragma once

#include <memory>
#include <entt/entt.hpp>
#include "events/windowEvents.h"
#include "core/application.h"

namespace Engine
{
	class NativeScript
	{
	public:
		NativeScript() : m_ent(entt::null), m_reg(Application::getInstance().m_reg){}
		NativeScript(entt::entity ent) : m_ent(ent), m_reg(Application::getInstance().m_reg){}
		virtual void onUpdate(float timestep) = 0;
		virtual void onKeyPressed(KeyPressedEvent& e) = 0;
	protected:
		entt::registry& m_reg;
		entt::entity m_ent;
	};
	class NativeScriptComponent
	{
	public:
		NativeScriptComponent() = default; //!< constructor 
		~NativeScriptComponent() = default;//!< default constructor
		void onUpdate(float timestep)
		{
			instance->onUpdate(timestep);
		}
		void onKeyPress(KeyPressedEvent& e) 
		{
			instance->onKeyPressed(e);
		}
		template <typename G, typename ...Args> void create(Args&& ... args)
		{
			G* ptr = new G(std::forward<Args>(args) ...);
			instance.reset(static_cast<NativeScript*>(ptr));
		}
	protected:
		std::shared_ptr<NativeScript> instance;

	};
}