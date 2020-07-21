#ifndef CRUISE_CONTROLLER_UI_H
#define CRUISE_CONTROLLER_UI_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <curses.h>

#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32.hpp>
#include "cruise_controller/constant.h"
#include "tutorial_interfaces/msg/vehicledynamics.hpp"
#include "tutorial_interfaces/msg/sensorinput.hpp"

using namespace std;

namespace cruise_controller
{
using std::placeholders::_1;

class UI :public rclcpp::Node
{
    public:
	UI();
	virtual ~UI();
	rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr trigger_pub;
    private:
        void take_input();
	protected:
        char key_press;
        int ascii_value;
        char value;
        volatile status_t status;
        

};
}//namespace cruise_controller

#endif //CRUISE_CONTROLLER_UI_H

