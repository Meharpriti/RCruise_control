#ifndef CRUISE_CONTROLLER_VEHICLE_STATUS_H
#define CRUISE_CONTROLLER_VEHICLE_STATUS_H

#include <iostream>
#include <string>
#include "cruise_controller/constant.h"
#include <std_msgs/msg/int32.hpp>

namespace cruise_controller
{
    class VehicleStatus
    {
        public:
        enum status_t_ checkstatus(std_msgs::msg::Int32::SharedPtr );
        private:
         volatile status_t status;
    };
}
#endif //CRUISE_CONTROLLER_VEHICLE_STATUS_H