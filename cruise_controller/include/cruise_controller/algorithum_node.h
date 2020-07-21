#ifndef CRUISE_CONTROLLER_ALGORITHUM_H
#define CRUISE_CONTROLLER_ALGORITHUM_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32.hpp>
//#include "cruise_controller/constant.h"
#include "tutorial_interfaces/msg/vehicledynamics.hpp"
#include "tutorial_interfaces/msg/sensorinput.hpp"
#include "cruise_controller/Acceleration.h"
#include "cruise_controller/VehicleStatus.h"


namespace cruise_controller
{
using std::placeholders::_1;

class cruise_algorithum :public rclcpp::Node
{
    public:
	    cruise_algorithum();
	    virtual ~cruise_algorithum();
		rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr acceleration_pub;
		rclcpp::Subscription<tutorial_interfaces::msg::Vehicledynamics>::SharedPtr vehicle_dynamics_sub;
		rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr velocity_sub,trigger_sub;
		cruise_controller::Acceleration acc; 
		cruise_controller::VehicleStatus state;
		void calculate_desired_acceleration(int32_t,int32_t);
		

	private:
        void stored_vehicle_dynamics(const tutorial_interfaces::msg::Vehicledynamics::SharedPtr);
        void stored_vehicle_velocity(const std_msgs::msg::Int32::SharedPtr);
		void trigger_callback(const std_msgs::msg::Int32::SharedPtr );
	protected:
        const std::string topic_name_;
		int32_t desired_velocity,Max_Inc,Min_Dec;
        uint32_t vehicle_velocity,jark;
        float desired_acceleration;
		volatile status_t status;

};
}
#endif //CRUISE_CONTROLLER_ALGORITHUM_H