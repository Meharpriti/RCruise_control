#ifndef CRUISE_CONTROLLER_CSV_READDYNAMICS_H
#define CRUISE_CONTROLLER_CSV_READDYNAMICS_H

#include "cruise_controller/IReadDynamics.h"
#include "tutorial_interfaces/msg/vehicledynamics.hpp"


namespace cruise_controller
{
    class Csv_ReadDynamics:public IVehicleDynamics<tutorial_interfaces::msg::Vehicledynamics>
    {
        public:
        tutorial_interfaces::msg::Vehicledynamics read_dynamics(const char* file) override;
        private:
        std::ifstream InputFile;
		std::string line,mass,load,refrence_velocity,cross_section,thrust,gas_pedal,drag_coefficient,air_density,Max_Inc,Min_Dec,Jerk; 
    };
    
}
#endif //CRUISE_CONTROLLER_CSV_READDYNAMICS_H