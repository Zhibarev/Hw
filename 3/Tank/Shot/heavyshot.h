#pragma once

#include "Shot/simpleshot.h"
#include "Shot/explosion.h"

/**
 * @brief Big SimpleShot with explose function
 */
class HeavyShot : public SimpleShot
{
public:
     HeavyShot(QPointF position, QPointF speed);

     /**
      * @brief generate explose (don't delete object)
      * @return
      */
     Explosion *explose();
};
