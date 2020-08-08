/*
 * File: SimulationResult.cpp
 * Purpose: To implement the generic interface for simluations
 * Author: Chris Chaffey
 * Copyright: Copyright © 2020 Chris Chaffey. All rights reserved.
 */

#include "SimulationResult.h"

namespace Simulation
{
	class pSimulationResult
	{
	public:
		pSimulationResult()
		{

		}

		virtual ~pSimulationResult()
		{

		}

	protected:
	private:
	};

	SimulationResult::SimulationResult()
	{
		p = std::make_unique<pSimulationResult>();
	}

	SimulationResult::~SimulationResult()
	{

	}

	uint64_t SimulationResult::GetDuration()
	{
		return 0;
	}
}