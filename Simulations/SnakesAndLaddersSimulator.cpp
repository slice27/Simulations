/*
 * File: SnakesAndLaddersSimulator.cpp
 * Purpose: To implement the interface for the Snakes and Ladders Simulation
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#include "SnakesAndLaddersSimulator.h"
#include "SnakesAndLaddersParams.h"

namespace Simulation
{

namespace SnakesAndLadders
{

class pSnakesAndLaddersSimulator
{
public:
	pSnakesAndLaddersSimulator(uint64_t executions, std::shared_ptr<SimulationParams> params)
	{
		
	}

private:
};

SnakesAndLaddersSimulator::SnakesAndLaddersSimulator(uint64_t executions, std::shared_ptr<SimulationParams> params):
	Simulation(executions, params)
{
	p = std::make_unique<pSnakesAndLaddersSimulator>(executions, params);
}

SnakesAndLaddersSimulator::~SnakesAndLaddersSimulator()
{
}

}; // SnakesAndLadders namespace

}; // Simulation namespace
