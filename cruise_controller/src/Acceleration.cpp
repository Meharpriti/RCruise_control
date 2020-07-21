#include "cruise_controller/Acceleration.h"

namespace cruise_controller
{
    std_msgs::msg::Float32 Acceleration::calculate_acceleration(float input_velocity,float desire_velocity,float jerk)
    {
        if((input_velocity<desire_velocity))
        {
            desired_acceleration.data=(desire_velocity-input_velocity);
            if(abs(desired_acceleration.data-init_acceleration)>jerk)
            {
                std::cout<<"Jerk Occures"<<std::endl;
            }
            std::cout<<"Desired_Acceleration:"<<desired_acceleration.data<<" "<<"InputVel:"<<input_velocity<<" "<<"Desired:"<<desire_velocity<<"\n"<<std::endl;
            init_acceleration= desired_acceleration.data;                 
        }else if(input_velocity>desire_velocity)
        {
            desired_acceleration.data=(desire_velocity-input_velocity);
            std::cout<<"Desired_Acceleration:"<<desired_acceleration.data<<" "<<"InputVel:"<<input_velocity<<" "<<"Desired:"<<desire_velocity<<"\n"<<std::endl;

            if(abs(desired_acceleration.data-init_acceleration)>jerk)
            {
                std::cout<<"Jerk Occures"<<std::endl;
            }
            init_acceleration= desired_acceleration.data;
        }
        return desired_acceleration;
    }
}

