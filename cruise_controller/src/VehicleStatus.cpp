#ifndef CRUISE_CONTROLLER_VEHICLESTATUS_STATUS_H
#define CRUISE_CONTROLLER_VEHICLESTATUS_STATUS_H

#include "cruise_controller/VehicleStatus.h"

namespace cruise_controller
{
    enum status_t_ VehicleStatus::checkstatus(std_msgs::msg::Int32::SharedPtr  status_)
    {
        if(status_->data==ON)
        {
            status=ON;
        }else if(status_->data==OFF)
        {
            status=OFF;
        }else if(status_->data==SET_INC)
        {
            status=SET_INC;
        }else if(status_->data==SET_DEC)
        {
            status=SET_DEC;
        }else if(status_->data==BREAK)
        {
            status=BREAK;
        }else if(status_->data==CLUTCH)
        {
            status=CLUTCH;
        }
        
        return status;   
    }

}

#endif //CRUISE_CONTROLLER_VEHICLESTATUS_STATUS_H