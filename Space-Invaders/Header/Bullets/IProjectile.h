#pragma once

namespace Projectile
{
	class IProjectile
	{
		virtual void setInitialPosition() = 0;
		virtual void setInitialDirection() = 0;
		virtual void move() = 0;
	};
}
