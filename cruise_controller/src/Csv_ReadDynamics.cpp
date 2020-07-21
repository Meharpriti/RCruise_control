#include "cruise_controller/Csv_ReadDynamics.h"

namespace cruise_controller
{
   tutorial_interfaces::msg::Vehicledynamics Csv_ReadDynamics::read_dynamics(const char* file)
   {
       auto vehicle_dynamics=tutorial_interfaces::msg::Vehicledynamics();
       std::cout<<"file path:"<<file<<std::endl;
       try
       {    
        InputFile.open(file, std::ios::out | std::ios::app);
        getline(InputFile,line,'\n');
        while(!InputFile.eof())
        {
            getline(InputFile, mass, ',');
            vehicle_dynamics.mass=std::stoi(mass);
            std::cout<<"mass:"<<vehicle_dynamics.mass<<std::endl;

            getline(InputFile, load, ',');
            vehicle_dynamics.load=std::stoi(load);
            std::cout<<"load:"<<vehicle_dynamics.load<<std::endl;

            getline(InputFile, gas_pedal, ',');
            vehicle_dynamics.gas_pedal=std::stoi(gas_pedal);
            std::cout<<"gas_pedal:"<<vehicle_dynamics.gas_pedal<<std::endl;

            getline(InputFile, drag_coefficient, ',');
            vehicle_dynamics.drag_coefficient=std::stof(drag_coefficient);
            std::cout<<"drag_coefficient:"<<vehicle_dynamics.drag_coefficient<<std::endl;

            getline(InputFile, air_density, ',');
            vehicle_dynamics.air_density=std::stof(air_density);
            std::cout<<"air_density:"<<vehicle_dynamics.air_density<<std::endl;

            getline(InputFile, cross_section, ',');
            vehicle_dynamics.cross_section_area=std::stoi(cross_section);
            std::cout<<"cross_section_area:"<<vehicle_dynamics.cross_section_area<<std::endl;

            getline(InputFile, thrust, ',');
            vehicle_dynamics.thrust=std::stoi(thrust);
            std::cout<<"thrust:"<<vehicle_dynamics.thrust<<std::endl;

            getline(InputFile, Max_Inc, ',');
            vehicle_dynamics.max_inc=std::stoi(Max_Inc.c_str());
            std::cout<<"Max_Inc:"<<vehicle_dynamics.max_inc<<std::endl;

            getline(InputFile, Min_Dec, ',');
            vehicle_dynamics.min_dec=std::stoi(Min_Dec.c_str());
            std::cout<<"Min_Dec:"<<vehicle_dynamics.min_dec<<std::endl;

            getline(InputFile, Jerk, ',');
            vehicle_dynamics.jerk=std::stoi(Jerk.c_str());
            std::cout<<"Min_Dec:"<<vehicle_dynamics.jerk<<std::endl;


            getline(InputFile, refrence_velocity, '\n');
            vehicle_dynamics.desired_velocity=std::stoi(refrence_velocity);
            std::cout<<"desired_velocity:"<<vehicle_dynamics.desired_velocity<<std::endl;
        }       
        }
        catch(std::exception &err)
        {
            std::cout<<"file at end"<<std::endl;
            InputFile.close();
        }
     return vehicle_dynamics;    
    }
}
