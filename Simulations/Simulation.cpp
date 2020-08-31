/*
 * File: Simulation.cpp
 * Purpose: To implement the generic interface for simluations
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#include <future>
#include <vector>
#include "Simulation.h"
#include "SimulationResult.h"

namespace Simulation
{
	class pSimulation
	{
	public:
		pSimulation(uint64_t executions, std::shared_ptr<SimulationParams> params) :
			mParams(params),
			mNumExecutions(executions)
		{
		}

	protected:
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

	private:
		friend class Simulation;

		std::shared_ptr<SimulationParams> mParams;
		uint64_t mNumExecutions;
	};



	Simulation::Simulation(uint64_t executions, std::shared_ptr<SimulationParams> params)
	{
		p = std::make_unique<pSimulation>(executions, params);
	}

	Simulation::~Simulation()
	{
	}

	void Simulation::SetupExecution()
	{
		p->startTime = std::chrono::steady_clock::now();
	}


	void Simulation::TearDownExecution()
	{
		p->endTime = std::chrono::steady_clock::now();
		auto diff = p->endTime - p->startTime;
	}

}