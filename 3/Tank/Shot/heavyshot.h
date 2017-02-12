#pragma once

#include "Shot/simpleshot.h"
#include "Shot/explosion.h"

class HeavyShot : public SimpleShot
{
public:
     HeavyShot(QPointF position, QPointF speed);

     Explosion *explose();
};
