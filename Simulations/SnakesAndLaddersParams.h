/*
 * File: SnakesAndLaddersParams.h
 * Purpose: To define the interface for the Snakes and Ladders Simulation parameters
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#ifndef SNAKESANDLADDERSPARAMS_H
#define SNAKESANDLADDERSPARAMS_H

#include "SimulationParams.h"

namespace Simulation
{

namespace SnakesAndLadders
{

class SnakesAndLaddersParams: public SimulationParams {
public:
    SnakesAndLaddersParams();
    SnakesAndLaddersParams(const SnakesAndLaddersParams& orig);
    virtual ~SnakesAndLaddersParams();
private:

};

}; // SnakesAndLadders namespace

}; // Simulation namespace

#endif /* SNAKESANDLADDERSPARAMS_H */

