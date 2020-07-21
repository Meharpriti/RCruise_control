#ifndef CRUISE_CONTROLLER_VELOCITY_H
#define CRUISE_CONTROLLER_VELOCITY_H

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include "tutorial_interfaces/msg/vehicledynamics.hpp"

namespace cruise_controller
{
    class Velocity
    {
        public:
        std_msgs::msg::Int32 calculate_velocity(tutorial_interfaces::msg::Vehicledynamics msg, float vehicle_acceleration_,float initial_velocity);        
        private:
        uint32_t M,L,Vref,A,Fp;
		int32_t u;
		float cd,rho,vehicle_velocity;
    };

}

#endif //CRUISE_CONTROLLER_VELOCITY_H