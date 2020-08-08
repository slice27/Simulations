/*
 * File: SimulationResult.h
 * Purpose: To define the generic interface for simluations
 * Author: Chris Chaffey
 * Copyright: Copyright © 2020 Chris Chaffey. All rights reserved.
 */

#ifndef _SIMULATION_RESULT_H_
#define _SIMULATION_RESULT_H_

#include <inttypes.h>
#include <memory>

namespace Simulation
{
	class pSimulationResult; //<! Forward declaration of private implementation.
	/**
	 * @author Chris Chaffey
	 * <h1>This class defines the generic result type that the simulation will return.</h1>
	 * <p>This result contains timing information on how long this Simulation took to execute.
	 */
	class SimulationResult
	{
	public:
		SimulationResult();
		virtual ~SimulationResult();

		/**
		 * @brief Returns the duration of this simulation
		 * <p>
		 * This function returns the number of milliseconds that this simulation took to complete execution.
		 * @return the number of milliseconds that this simulation took to execute.
		 */
		uint64_t GetDuration();

	private:
		std::unique_ptr<pSimulationResult> p;
	};

}

#endif
