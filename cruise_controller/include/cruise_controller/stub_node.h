#ifndef CRUISE_CONTROLLER_STUB_H
#define CRUISE_CONTROLLER_STUB_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>

#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include "cruise_controller/constant.h"
#include "tutorial_interfaces/msg/vehicledynamics.hpp"
#include "tutorial_interfaces/msg/sensorinput.hpp"
#include "cruise_controller/Csv_ReadDynamics.h"
#include "Velocity.h"

namespace cruise_controller
{
using std::placeholders::_1;
class stub : public rclcpp::Node
{
	public:
	    stub();
	    virtual ~stub();
		rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr velocity_publisher_;
		rclcpp::Publisher<tutorial_interfaces::msg::Vehicledynamics>::SharedPtr vehicle_dynamics_publisher;
		rclcpp::Subscription<tutorial_interfaces::msg::Sensorinput>::SharedPtr rosbag_subscriber_;
	private:
	    void stored_data(const tutorial_interfaces::msg::Sensorinput::SharedPtr) ;
	    void get_velocity(float,float);
		void get_vehicle_dynamics(); 
		float vehicle_acceleration,timestamp;
		tutorial_interfaces::msg::Vehicledynamics vehicle_dynamics;
		cruise_controller::Velocity vel;
	protected:
        const std::string topic_name_;
		float initial_velocity=0,initial_timestamp=0,vehicle_velocity;
				
};
}
#endif //CRUISE_CONTROLLER_STUB_H
