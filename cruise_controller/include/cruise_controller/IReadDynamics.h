#ifndef CRUISE_CONTROLLER_IREADDYNAMICS_H
#define CRUISE_CONTROLLER_IREADDYNAMICS_H

#include <string>
#include <fstream>
#include <iostream>


namespace cruise_controller
{
    template<typename M>
    class IVehicleDynamics
    {
        public:
        virtual M read_dynamics(const char* file) = 0; 
    };  
}

#endif //CRUISE_CONTROLLER_IREADDYNAMICS_H

