#ifndef _SIMULATION_RUNNER_IMPL_H_
#define _SIMULATION_RUNNER_IMPL_H_

#include <vector>
#include "SimulationRunner.h"

namespace Simulation
{
	class pSimulationRunner
	{
	public:
		pSimulationRunner(uint64_t maxExecutions, uint32_t numThreads) :
			mMaxExecutions(maxExecutions),
			mNumThreads(numThreads)
		{
		}

	private:
		friend class SimulationRunner<class T>;

		uint64_t mMaxExecutions;
		uint32_t mNumThreads;
		std::vector<std::future<std::unique_ptr<SimulationResult>>> results;
	};

	template <class Simulation>
    SimulationRunner<Simulation>::SimulationRunner(uint64_t maxExecutions, uint32_t numThreads)
    {

    }

    template <class Simulation>
    SimulationRunner<Simulation>::~SimulationRunner()
    {
    }

    template <class Simulation>
    void SimulationRunner<Simulation>::SetMaxExecutions(uint64_t maxExecutions)
    {
        p->mMaxExecutions = maxExecutions;
    }

    template <class Simulation>
    void SimulationRunner<Simulation>::SetNumThreads(uint32_t numThreads)
    {
        p->mNumThreads = numThreads;
    }


    template<class Simulation>
    SimulationResult SimulationRunner<Simulation>::Start(std::shared_ptr<SimulationParams> params)
    {
        uint64_t executionsPerThread = p->mMaxExecutions / p->mNumThreads;
        uint64_t extraExecutions = p->mMaxExecutions % p->mNumThreads;

        for (uint32_t i = 0; i < p->mNumThreads; ++i)
        {
            uint64_t executions = (i < extraExecutions ? executionsPerThread + 1 : executionsPerThread);
            Simulation simulation(executions, params);
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
