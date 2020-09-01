/*
 * File: SimulationRunner.h
 * Purpose: To define the interface for running simluations
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
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
         * @param [in] maxExecutions The number of times this simulation should be run.
         */
        void SetMaxExecutions(uint64_t maxExecutions);

        /**
         * @brief Sets the number of threads on which to run this simulation.
         * <p>
         * This function will override the number of threads this simulation will run on as set in the constructor of the
         * Simulation.
         * @param [in] numThreads the maximum number of threads on which to execute this simulation
         */
        void SetNumThreads(uint32_t numThreads);

        /**
         * @brief Starts the simulation.
         * <p>
         * This function will drive the simulation, starting the appropriate number of threads, and calling the Execute method, and
         * start profiling the execution.
         * @param [in] params The parameters used by this simulation.
         * @return the duration of executing the total simulation.
         * @see Execute
         */
        virtual SimulationResult Start(std::shared_ptr<SimulationParams> params);

    private:
        std::unique_ptr<pSimulationRunner> p;
    };

}


#endif
