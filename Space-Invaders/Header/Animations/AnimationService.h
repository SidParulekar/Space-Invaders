#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Animations\AnimationSystem.h"
#include "SFML/System/Vector2.hpp"

namespace Animation
{
	enum class AnimationType
	{
		EXPLOSION,
	};

	class AnimationService
	{
	private:
		std::vector<AnimationSystem*> animation_system_list;
		std::vector<AnimationSystem*> flagged_animation_system_list;

		AnimationSystemConfig getAnimationSystemConfig(AnimationType animation_type);
		sf::String getAnimationTexturePath(AnimationType animation_type);
		void destroyFlaggedAnimationSystem();
		void destroy();

	public:
		AnimationService();
		virtual ~AnimationService();

		void initialize();
		void update();
		void render();

		void reset();

		void spawnAnimationSystem(sf::Vector2f position, AnimationType animation_type);
		void destroyAnimationSystem(AnimationSystem* animation_system);
	};
}