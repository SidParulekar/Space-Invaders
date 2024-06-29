#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Animations\AnimationService.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Animations\AnimationSystemConfigData.h"

namespace Animation
{
	AnimationService::AnimationService() { }

	void AnimationService::initialize() { }

	void AnimationService::update()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			animation_system->update();

		destroyFlaggedAnimationSystem();
	}

	void AnimationService::render()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			animation_system->render();
	}

	void AnimationService::spawnAnimationSystem(sf::Vector2f position, AnimationType animation_type)
	{
		AnimationSystem* animation_system = new AnimationSystem(getAnimationSystemConfig(animation_type), getAnimationTexturePath(animation_type));
		animation_system->initialize(position);
		animation_system_list.push_back(animation_system);
	}

	AnimationSystemConfig AnimationService::getAnimationSystemConfig(AnimationType animation_type)
	{
		switch (animation_type)
		{
		case Animation::AnimationType::EXPLOSION:
			return explosion_animation_config;
		}
	}

	sf::String AnimationService::getAnimationTexturePath(AnimationType animation_type)
	{
		switch (animation_type)
		{
		case Animation::AnimationType::EXPLOSION:
			return Config::explosion_texture_path;
		}
	}

	void AnimationService::destroyAnimationSystem(AnimationSystem* animation_system)
	{
		flagged_animation_system_list.push_back(animation_system);
		animation_system_list.erase(std::remove(animation_system_list.begin(), animation_system_list.end(), animation_system), animation_system_list.end());
	}


	void AnimationService::destroyFlaggedAnimationSystem()
	{
		for (AnimationSystem* particle_system : flagged_animation_system_list)
			delete (particle_system);

		flagged_animation_system_list.clear();
	}

	AnimationService::~AnimationService() { destroy(); }

	void AnimationService::destroy()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			delete (animation_system);
	}

	void AnimationService::reset() { destroy(); }
}