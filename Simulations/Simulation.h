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
         * @brief Gets the current statistics of this simulation
         * <p>
         * This function will return how many executions have been completed, as well as the total number of executions for this
         * simulation.  This can be used to get the runtime progress of this simulation.
         * @param [out] currExecution The current iteration of the simulation
         * @param [out] totalExecutions the total number of iterations this simulation will execute
         */
        void GetRuntimeStatistics(uint64_t& currExecution, uint64_t& totalExecutions);

        /**
         * @brief Sets up the base class of the simulation.
         * <p>
         * This method sets up the base class of the simulation.  This method will be called first in the SimulationRunner prior to
         * calling the Execute method.
         * @see TearDownExecution
         * @see Execute
         */
        virtual void SetupExecution();

        /**
         * @brief Tears down the base class of the simulation
         * <p>
         * This method tears down the base class of the simulation.  This method will be the last method called in the
         * SimulationRunner after the Execute method has completed.
         * @see SetupExecution
         * @see Execute
         */
        
        /**
         * @brief The simulation code to be executed.
         * <p>
         * This is where the simluation implementation will exist.  This method will be called after SetupExecution and prior to 
         * TearDownExecution.  The implementor must execute 
         * @return a unique_ptr to the result of this simulation.
         * @see SetMaxExecutions
         * @see SetNumThreads
         */
        virtual std::unique_ptr<SimulationResult> Execute() = 0;
        
        virtual void TearDownExecution();

    protected:
        /**
         * @brief Returns the number of times this simulation must execute
         * <p>
         * This function will return the total number of times that this simulation must be executed before it is completed.  Any 
         * implementer of a derived Simulation must 
         * @return 
         */
        uint64_t GetMaxExecutions();

    private:
        std::unique_ptr<pSimulation> p;  ///!< Pointer to private implementation.

    };
}

#endif
