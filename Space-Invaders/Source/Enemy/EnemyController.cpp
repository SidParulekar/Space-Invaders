#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyController.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyModel.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\Enemy\EnemyView.h"
#include "C:\Users\sidpa\Documents\GitHub\Space-Invaders\Space-Invaders\Header\ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_model = new EnemyModel();
		enemy_view = new EnemyView();
	}
	
	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this); 
	}

	void EnemyController::update()
	{
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyController::~EnemyController()
	{
		delete enemy_model;
		delete enemy_view;
		enemy_model = nullptr;
		enemy_view = nullptr;
	}
}