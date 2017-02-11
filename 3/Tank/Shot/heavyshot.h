#pragma once

#include "Shot/simpleshot.h"
#include "explosion.h"

class HeavyShot : public SimpleShot
{
public:
     HeavyShot(QPointF position, QPointF speed);

     Explosion *explose();
};
