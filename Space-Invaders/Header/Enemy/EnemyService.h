#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:
		const float spawn_interval = 3.0f;

		std::vector<EnemyController*> enemy_list;

		float spawn_timer;

		EnemyType getRandomEnemyType();

		EnemyController* createEnemy(EnemyType enemy_type);

		void updateSpawnTimer();
		void processEnemySpawn();
		void destroy();

	public:

		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();

		void destroyEnemy(EnemyController* enemy_controller);
		
	};
}