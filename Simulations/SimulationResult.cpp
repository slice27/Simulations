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
		pSimulationResult(uint64_t duration = 0):
			mDuration(duration)
		{
		}

		virtual ~pSimulationResult()
		{
		}

		pSimulationResult(const pSimulationResult& simulation):
			mDuration(simulation.mDuration)
		{
		}

	protected:
		friend class SimulationResult;

		pSimulationResult Sum(const pSimulationResult& addition)
		{
			pSimulationResult ret;
			ret.mDuration = this->mDuration + addition.mDuration;
			return ret;
		}

	private:
		uint64_t mDuration;
	};

	SimulationResult::SimulationResult(uint64_t duration)
	{
		p = std::make_unique<pSimulationResult>(duration);
	}

	SimulationResult::~SimulationResult()
	{
	}

	SimulationResult::SimulationResult(const SimulationResult& simulation):
		p(std::make_unique<pSimulationResult>(*simulation.p))
	{
	}

	SimulationResult SimulationResult::operator+(const SimulationResult& addition)
	{
		SimulationResult ret;
		ret.p = std::make_unique<pSimulationResult>(std::move(p->Sum(*addition.p)));
		return ret;
	}

	uint64_t SimulationResult::GetDuration()
	{
		return p->mDuration;
	}
}