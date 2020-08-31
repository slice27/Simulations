/*
 * File: SimulationRunner.h
 * Purpose: To define the interface for running simluations
 * Author: Chris Chaffey
 * Copyright: Copyright � 2020 Chris Chaffey. All rights reserved.
 */

#ifndef _SIMULATION_PARAMS_H_
#define _SIMULATION_PARAMS_H_

#include <memory>

namespace Simulation
{
    class pSimulationParams;  ///!< Forward declaration of private implementation.

    /**
     * @author Chris Chaffey
     * @brief This class defines the generic parameters to be passed to each simulation object.
     */
    class SimulationParams
    {
    public:
        SimulationParams();
        virtual ~SimulationParams();

        /**
         * @brief Sets the number of executions this simulation will run.
         * <p>
         * This method will set the number of executions that the simulation will run.  This must be called before the simulation
         * is executed.
         * @param numExecutions The number of times the simulation will execute.
         */
        void SetNumExecutions(uint64_t numExecutions);

    private:
        std::unique_ptr<pSimulationParams> p;
    };

}

#endif
