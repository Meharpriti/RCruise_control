#include "cruise_controller/stub_node.h"

namespace cruise_controller
{
stub::stub(): Node("stub")
{
    vehicle_dynamics_publisher = this->create_publisher<tutorial_interfaces::msg::Vehicledynamics>(cruise_controller::kEmittedDynamics, publisher_queue_size);    
    velocity_publisher_ = this->create_publisher<std_msgs::msg::Int32>(cruise_controller::kEmittedVelocity, publisher_queue_size);
    rosbag_subscriber_ = this->create_subscription<tutorial_interfaces::msg::Sensorinput>(cruise_controller::kConsumeRosbag, subscriber_queue_size, std::bind(&stub::stored_data, this,_1));
    get_vehicle_dynamics();
}
stub::~stub() {}
void stub::get_vehicle_dynamics()
{
    std::cout<<"Vehicle Dynamics:"<<std::endl;
    auto dynamics=std::shared_ptr<cruise_controller::IVehicleDynamics<tutorial_interfaces::msg::Vehicledynamics>>(new cruise_controller::Csv_ReadDynamics);
    vehicle_dynamics=dynamics->read_dynamics(InputFilePath);

    vehicle_dynamics_publisher->publish(vehicle_dynamics);
    std::cout<<vehicle_dynamics.desired_velocity<<std::endl;
}
void stub::stored_data(const tutorial_interfaces::msg::Sensorinput::SharedPtr input)
{    
    vehicle_acceleration=input->acceleration;
    timestamp=input->timestamp;
    std::cout<<"\n timestamp:"<<input->timestamp<<"  "<<"acceleration:"<<input->acceleration<<std::endl;
    get_velocity(vehicle_acceleration,timestamp);
}
void stub::get_velocity(float vehicle_acceleration_,float timestamp_)
{    
    auto velocity_msg=std_msgs::msg::Int32();
    velocity_msg=vel.calculate_velocity(vehicle_dynamics,vehicle_acceleration_,initial_velocity);
    std::cout<<"Velocity_current: "<<velocity_msg.data<<std::endl;
    initial_velocity=velocity_msg.data;
    velocity_publisher_->publish(velocity_msg);
}
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  std::shared_ptr<rclcpp::Node> sensor;
  sensor=std::make_shared<cruise_controller::stub>();
  rclcpp::spin(sensor);
  rclcpp::shutdown();
  return 0;
}

