#ifndef _SIMULATION_RUNNER_IMPL_H_
#define _SIMULATION_RUNNER_IMPL_H_

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

}

#endif
