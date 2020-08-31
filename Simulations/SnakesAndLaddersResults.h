/*
 * File: SnakesAndLaddersResults.h
 * Purpose: To define the interface for the Snakes and Ladders Simulation results
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#ifndef SNAKESANDLADDERSRESULTS_H
#define SNAKESANDLADDERSRESULTS_H

#include "SimulationResult.h"

namespace SnakesAndLadders
{

class SnakesAndLaddersResults: public Simulation::SimulationResult {
public:
    SnakesAndLaddersResults();
    SnakesAndLaddersResults(const SnakesAndLaddersResults& orig);
    virtual ~SnakesAndLaddersResults();
private:

};

};

#endif /* SNAKESANDLADDERSRESULTS_H */

