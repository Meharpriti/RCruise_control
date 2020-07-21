#ifndef CRUISE_CONTROLLER_ACCELERATION_H
#define CRUISE_CONTROLLER_ACCELERATION_H

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float32.hpp>
#include "tutorial_interfaces/msg/vehicledynamics.hpp"

namespace cruise_controller
{
    class Acceleration
    {
        public:
        std_msgs::msg::Float32 calculate_acceleration(float input_velocity,float desire_velocity,float jerk);
        private:
        std_msgs::msg::Float32 desired_acceleration;
        float init_acceleration=0;
    };
}

#endif //CRUISE_CONTROLLER_ACCELERATION_H