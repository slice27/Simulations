/*
 * File: SimulationRunner.h
 * Purpose: To define the interface for running simluations
 * Author: Chris Chaffey
 * Copyright: Copyright © 2020 Chris Chaffey. All rights reserved.
 */

#ifndef _SIMULATION_RUNNER_H_
#define _SIMULATION_RUNNER_H_

#include <memory>
#include "Simulation.h"
#include "SimulationParams.h"
#include "SimulationResult.h"

namespace Simulation
{
	class pSimulationRunner; ///<! Forward declaration of private implementation of the Simulation Runner.

	template<class Simulation>
	class SimulationRunner
	{
		SimulationRunner(uint64_t maxExecutions, uint32_t numThreads);
		virtual ~SimulationRunner();

		SimulationRunner(const SimulationRunner&) = delete;
		SimulationRunner& operator=(const SimulationRunner&) = delete;
		SimulationRunner(SimulationRunner&&) = delete;
		SimulationRunner& operator=(SimulationRunner&&) = delete;

		/**
		 * @brief Sets the maximum number of times this simulation will execute
		 * <p>
		 * This function override the maximum number of times this simulation will run as set in the constructor of the Simulation
		 * class.
		 * @param maxExecutions The number of times this simulation should be run.
		 */
		void SetMaxExecutions(uint64_t maxExecutions);

		/**
		 * @brief Sets the number of threads on which to run this simulation.
		 * <p>
		 * This function will override the number of threads this simulation will run on as set in the constructor of the
		 * Simulation.
		 * @param numThreads the maximum number of threads on which to execute this simulation
		 */
		void SetNumThreads(uint32_t numThreads);

		/**
		 * @brief Starts the simulation.
		 * <p>
		 * This function will drive the simulation, starting the appropriate number of threads, and calling the Execute method, and
		 * start profiling the execution.
		 * @param params The parameters used by this simulation.
		 * @return the duration of executing the total simulation.
		 * @see Execute
		 */
		virtual SimulationResult Start(std::shared_ptr<SimulationParams> params);

	private:
		std::unique_ptr<pSimulationRunner> p;
	};

	template <class T>
	SimulationRunner<T>::SimulationRunner(uint64_t maxExecutions, uint32_t numThreads)
	{

	}

	template <class T>
	SimulationRunner<T>::~SimulationRunner()
	{
	}

	template <class T>
	void SimulationRunner<T>::SetMaxExecutions(uint64_t maxExecutions)
	{
		p->mMaxExecutions = maxExecutions;
	}

	template <class T>
	void SimulationRunner<T>::SetNumThreads(uint32_t numThreads)
	{
		p->mNumThreads = numThreads;
	}


	template<class T>
	SimulationResult SimulationRunner<T>::Start(std::shared_ptr<SimulationParams> params)
	{
		uint64_t executionsPerThread = p->mMaxExecutions / p->mNumThreads;
		uint64_t extraExecutions = p->mMaxExecutions % p->mNumThreads;
	
		for (uint32_t i = 0; i < p->mNumThreads; ++i)
		{
			uint64_t executions = (i < extraExecutions ? executionsPerThread + 1 : executionsPerThread);
			T simulation(params);
			//p->futures.push_back(simulation)
		}
		{
			//std::packaged_task<uint64_t(const Lotto::Lottery&)> package{ LotteryTask };
			//futures.push_back(package.get_future());
			//std::thread t{ std::move(package), lotto };
			//t.detach();
		}
	}

}


#endif
