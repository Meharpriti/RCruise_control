#include "cruise_controller/algorithum_node.h"

namespace cruise_controller
{
cruise_algorithum::cruise_algorithum(): Node("algorithum_node")
{
    acceleration_pub = this->create_publisher<std_msgs::msg::Float32>(cruise_controller::kEmittedVelocity, publisher_queue_size);
    vehicle_dynamics_sub = this->create_subscription<tutorial_interfaces::msg::Vehicledynamics>(cruise_controller::kEmittedDynamics, 1,std::bind(&cruise_algorithum::stored_vehicle_dynamics, this,_1));    
    trigger_sub= this->create_subscription<std_msgs::msg::Int32>(cruise_controller::kTriggerStatus, subscriber_queue_size, std::bind(&cruise_algorithum::trigger_callback, this,_1));
    velocity_sub = this->create_subscription<std_msgs::msg::Int32>(cruise_controller::kEmittedVelocity, subscriber_queue_size, std::bind(&cruise_algorithum::stored_vehicle_velocity, this,_1));    
}
cruise_algorithum::~cruise_algorithum() { }

void cruise_algorithum::trigger_callback(const std_msgs::msg::Int32::SharedPtr msg)
{
    status=state.checkstatus(msg);
    auto vehicle_dynamics=tutorial_interfaces::msg::Vehicledynamics();
    if(status==SET_INC)
    {
        desired_velocity=desired_velocity+Max_Inc;
    }else if(status==SET_DEC)
    {
        desired_velocity=desired_velocity-Min_Dec;
    }else if(status==BREAK || status==CLUTCH)
    {
        std::cout<<"Break/Cluch is Applied...Restart the cruise controller"<<std::endl;
        desired_velocity=vehicle_dynamics.desired_velocity;
    }
    std::cout<< "trigger:"<<status<<std::endl;
}

void cruise_algorithum::stored_vehicle_dynamics(const tutorial_interfaces::msg::Vehicledynamics::SharedPtr msg)
{   
    desired_velocity=msg->desired_velocity;
    jark=msg->jerk;
    Max_Inc=msg->max_inc;
    Min_Dec=msg->min_dec;
    std::cout<<"Received Desired velocity::"<<msg->desired_velocity<<std::endl;
}
void cruise_algorithum::stored_vehicle_velocity(const std_msgs::msg::Int32::SharedPtr msg)
{
    vehicle_velocity=msg->data;
    std::cout<<"Received velocity"<<vehicle_velocity<<std::endl;
    calculate_desired_acceleration(vehicle_velocity,desired_velocity);        
}
void cruise_algorithum::calculate_desired_acceleration(int32_t input_velocity,int32_t desire_velocity)
{
    if(input_velocity>=40 && (status==ON||status==SET_INC||status==SET_DEC))
    {
        auto desired_acceleration_=acc.calculate_acceleration(input_velocity,desire_velocity,jark);
             
    } else
    {
        desired_acceleration=0;
        std::cout<<"Desired_Acceleration:"<<desired_acceleration<<"\n"<<std::endl;
    }
}
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);  
  rclcpp::spin(std::make_shared<cruise_controller::cruise_algorithum>());
  rclcpp::shutdown();
  return 0;
}

