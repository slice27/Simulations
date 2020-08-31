/*
 * File: Simulation.h
 * Purpose: To define the generic interface for simluations
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include <inttypes.h>
#include <future>
#include <memory>
#include "SimulationParams.h"
#include "SimulationResult.h"

namespace Simulation
{
    class pSimulation;  ///<! Forward declaration of private implementation class.

    /**
     * @author Chris Chaffey
     * @brief This class defines the generic interface to simulations.
     */
    class Simulation
    {
    public:
        Simulation(uint64_t executions, std::shared_ptr<SimulationParams> params);
        virtual ~Simulation();

        /**
         * @brief The simulation code to be executed.
         * <p>
         * This is where the simluation implementation will exist.  This method will be staged in numThreads threads for the an
         * appropriate number maxExecutions.
         * @return a future containing the result of this simulation.
         * @see SetMaxExecutions
         * @see SetNumThreads
         */
        virtual std::future<std::unique_ptr<SimulationResult>> Execute() = 0;  

    protected:
        /**
         * @brief Sets up the base class of the simulation.
         * <p>
         * This method sets up the base class of the simulation.  This method should be called first, in the implementation of the
         * Execute method.
         * @see Execute
         */
        virtual void SetupExecution();

        /**
         * @brief Tears down the base class of the simulation
         * <p>
         * This method tears down the base class of the simulation.  This method should be the last method called in the Execute
         * method of the simulation.
         * @see Execute
         */
        virtual void TearDownExecution();

    private:
        std::unique_ptr<pSimulation> p;  ///!< Pointer to private implementation.

    };
}

#endif
