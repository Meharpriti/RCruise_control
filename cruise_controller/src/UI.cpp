#include "cruise_controller/UI.h"
namespace cruise_controller
{
UI::UI(): Node("UI")
{
    trigger_pub = this->create_publisher<std_msgs::msg::Int32>(cruise_controller::kTriggerStatus, publisher_queue_size);
    take_input();
}
UI::~UI() { }
void UI::take_input()
{
    cout<<"\n\t\t\tPress Key \n\t\t\tPress ESC to EXIT\n\n\n";
    while(1)
    {
    cin >> key_press;
    ascii_value=key_press;
    value=key_press;
    if(ascii_value==27) // For ESC
     break;
   cout<<"KEY Pressed-> \" "<<key_press<<"\n";
   switch(value)
   {
        case 'o' :
            cout << "Cruise System turn ON" << endl;
            status=ON; 
            break;
        case 'f' :
            cout << "Cruise System turn OFF" << endl;
            status=OFF; 
            break;
        case '+' :
            cout << "Increse SET Velocity" << endl;
            status=SET_INC; 
            break;
        case '-' :
            cout << "Decrease SET Velocity" << endl;
            status=SET_DEC; 
            break;
        case 'b' :
            cout << "Decrease SET Velocity" << endl;
            status=BREAK; 
            break;
        case 'c' :
            cout << "Decrease SET Velocity" << endl;
            status=CLUTCH; 
            break;
        default :
            cout << "Invalid input" << endl;
            exit(0);
    }
    auto status_=std_msgs::msg::Int32();
    status_.data=status;
    trigger_pub->publish(status_);
    cout << "publish"<<status << endl;
  }
}
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cruise_controller::UI>());
  rclcpp::shutdown();
  return 0;
}
