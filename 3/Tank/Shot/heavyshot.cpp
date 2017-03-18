#include "heavyshot.h"

HeavyShot::HeavyShot(QPointF position, QPointF speed):
    SimpleShot(position, speed)
{
    setRadius(10);
}

Explosion *HeavyShot::explose()
{
    return new Explosion(pos());
}
