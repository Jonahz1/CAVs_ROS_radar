# CAVs GRA Prompt Github

## 1. System Setup

1. Ubuntu 18.04.4 LTS
2. ROS Melodic
3. VMware Virtual Machine
4. Python 2.7.17

## 2. Dependencies

1. pip
2. python-can:
3. cantools: 
4. kvaser linux and SDK: https://www.kvaser.com/linux-drivers-and-sdk/ 

## 3. Radar Msgs

1. For ROS Melodic, radar_msgs/RadarDection is avaliable [here](https://github.com/astuff/astuff_sensor_msgs/tree/melodic/radar_msgs).
2. The radar_msg package needs be placed \/\<catkin_ws\>/src/\<your_ros_package\>/<radar_msg_package> 
3. Build the project in the root folder of the workspace(./cavs_ws) ```catkin_make```

## 4. Running Test Code

1. Uncomment test code lines in scripts/radar_parser.py
2. Build the ROS project in the root folder of workspace(./cavs_ws) ```catkin_make```
3. Enable kvaser virtual CAN Bus (test program uses virtual channel 0)
4. In a new terminal window enter ```roscore``` to start the ROS Master 
   - In a new terminal window source the catkin_ws ```source ./cavs_ws/devel/setup.bash```
5. In the same terminal you can now run ```rosrun cavs_radar_example radar_parser.py```
6. In a new terminal window, start the CAN Bus sending program ```python ./cavs_ws/documents/test_code/sender.py```
7. ROS Node radar_parser should begin to output recieving messages

