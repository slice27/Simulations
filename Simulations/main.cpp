#include <iostream>
#include "Simulation.h"
#include "SimulationResult.h"

int main()
{
    Simulation::SimulationResult r1(10);
    Simulation::SimulationResult r2(15);

    Simulation::SimulationResult result = r1 + r2;
    /*
    MySimulationParams params = { };
    SimulationRunner<MySimulation> runner(myParams);
    MySimulationResults results = runner.execute();

    MySimulationParams::PrintResults(results);
    */
}
