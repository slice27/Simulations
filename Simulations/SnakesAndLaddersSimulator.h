/*
 * File: SnakesAndLaddersSimulator.h
 * Purpose: To define the interface for the Snakes and Ladders Simulation
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#ifndef SNAKESANDLADDERSSIMULATOR_H
#define SNAKESANDLADDERSSIMULATOR_H

#include <memory>
#include "Simulation.h"

namespace Simulation
{
namespace SnakesAndLadders
{

class pSnakesAndLaddersSimulator;  //<! Forward declaration of private implementation.

class SnakesAndLaddersSimulator: public Simulation {
public:
    SnakesAndLaddersSimulator(uint64_t executions, std::shared_ptr<SimulationParams> params);
    virtual ~SnakesAndLaddersSimulator();

    SnakesAndLaddersSimulator(const SnakesAndLaddersSimulator& orig) = delete;
    SnakesAndLaddersSimulator& operator=(const SnakesAndLaddersSimulator&) = delete;
    SnakesAndLaddersSimulator(SnakesAndLaddersSimulator&&) = delete;
    SnakesAndLaddersSimulator& operator=(SnakesAndLaddersSimulator&&) = delete;

private:
    std::unique_ptr<pSnakesAndLaddersSimulator> p;
};

}; // SnakesAndLadders namespace
}; // Simulation namespace

#endif /* SNAKESANDLADDERSSIMULATOR_H */

