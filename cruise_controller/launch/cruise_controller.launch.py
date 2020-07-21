from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cruise_controller',
            node_executable='UI',
            node_name='UI',
	    output='screen'	    
        ),
	Node(
            package='cruise_controller',
            node_executable='cruise',
            node_name='algorithm_node',
	    output='screen'
        ),
        Node(
            package='cruise_controller',
            node_executable='stub',
            node_name='stub',
	    output='screen'
        )
        
    ])

