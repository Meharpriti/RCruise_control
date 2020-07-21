#include "cruise_controller/Velocity.h"

namespace cruise_controller
{

    std_msgs::msg::Int32 Velocity::calculate_velocity(tutorial_interfaces::msg::Vehicledynamics vehicle_dynamics,float vehicle_acceleration_,float initial_velocity)
    {
        M=vehicle_dynamics.mass;
        L=vehicle_dynamics.load;
        u=vehicle_dynamics.gas_pedal;
        cd=vehicle_dynamics.drag_coefficient;
        rho=vehicle_dynamics.air_density;
        A=vehicle_dynamics.cross_section_area;
        Fp=vehicle_dynamics.thrust;
        std::cout<<" initial velocity: "<<initial_velocity<<std::endl;
        float a=abs((Fp*u)-((M+L)*vehicle_acceleration_));
        float b=0.5*rho*cd*A;
        std::cout<<"a"<<a<<"  "<<"b"<<b<<std::endl;
        if(vehicle_acceleration_==0)
        {
            vehicle_velocity=initial_velocity;
        }
        else if(vehicle_acceleration_>0)
        {
            vehicle_velocity=initial_velocity+sqrt(a/b);            
        }else if(vehicle_acceleration_<0)
        {
            vehicle_velocity=initial_velocity-sqrt(a/b);            
        }
                
        std::cout<<"vehicle_velocity:----"<<vehicle_velocity<<std::endl;
        auto velocity_msg=std_msgs::msg::Int32();
        velocity_msg.data=(vehicle_velocity);
        return velocity_msg;
    }  
}