FROM ros:eloquent-ros-base

# install ros build tools
RUN apt-get update && apt-get install -y \
      python3-colcon-common-extensions && \
    rm -rf /var/lib/apt/lists/*

# clone ros package repo
ENV ROS_WS /opt/ros_ws
RUN mkdir -p $ROS_WS/src
WORKDIR $ROS_WS
RUN git -C src clone \
    -b cruise_control \
    https://meharpritim:meheravtar02%40@gitlab-public.kpit.com/meharpritim/cruise_control.git

# install ros package dependencies
RUN apt-get update && \
    apt-get install libboost-dev -y &&\
    apt-get install libncurses5-dev libncursesw5-dev -y &&\
    apt-get update && \
    rosdep update && \
    rosdep install -y \
      --from-paths \
        src/cruise_control/cruise_controller \
        src/cruise_control/tutorial_interfaces \
      --ignore-src && \
    rm -rf /var/lib/apt/lists/*

# build ros package source
RUN . /opt/ros/$ROS_DISTRO/setup.sh && \
    colcon build \
      --packages-select \
        cruise_controller \
        tutorial_interfaces \
      --cmake-args \
        -DCMAKE_BUILD_TYPE=Release

# copy ros package install via multi-stage
FROM ros:eloquent-ros-core
ENV ROS_WS /opt/ros_ws
COPY --from=0  $ROS_WS/install $ROS_WS/install

# source ros package from entrypoint
RUN sed --in-place --expression \
      '$isource "$ROS_WS/install/setup.bash"' \
      /ros_entrypoint.sh

# run ros package launch file
CMD ["ros2", "launch", "cruise_controller", "cruise_controller.launch.py"]


