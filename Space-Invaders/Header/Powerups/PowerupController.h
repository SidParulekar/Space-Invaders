#pragma once
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Collectibles\ICollectible.h"
#include "..\..\..\..\..\GitHub\Space-Invaders\Space-Invaders\Header\Collisions\ICollider.h"

namespace Powerup
{
    class PowerupView;
    class PowerupModel;

    enum class PowerupType;

    class PowerupController : public Collectible::ICollectible, public Collision::ICollider
    {
    protected:
        PowerupView* powerup_view;
        PowerupModel* powerup_model;

        virtual void applyPowerup() = 0;

        void updatePowerupPosition();
        void handleOutOfBounds();

    public:
        PowerupController(PowerupType type);
        virtual ~PowerupController();

        void initialize(sf::Vector2f position) override;
        void update() override;
        void render() override;

        void onCollected() override;

        sf::Vector2f getCollectiblePosition() override;
        PowerupType getPowerupType();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}