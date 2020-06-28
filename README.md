# CAVs GRA Prompt Github

## 1. System Setup

1. Ubuntu 18.04.4 LTS
2. ROS Melodic
3. VMware Virtual Machine
4. Python 2.7.17

## 2. Project Dependencies

1. [pip](https://pip.pypa.io/en/stable/)
2. [python-can](https://python-can.readthedocs.io/en/master/)
3. [cantools](https://pypi.org/project/cantools/) 
4. [kvaser linux and SDK](https://www.kvaser.com/linux-drivers-and-sdk/) 

## 3. Radar Msgs

1. For ROS Melodic, radar_msgs/RadarDection is avaliable [here](https://github.com/astuff/astuff_sensor_msgs/tree/melodic/radar_msgs).
2. The radar_msg package needs be placed \/\<catkin_ws\>/src/\<your_ros_package\>/<radar_msg_package> 
3. Build the project in the root folder of the workspace(./cavs_ws) ```catkin_make```
4. The radar_msg should be avaliable now. This message type can be seen by entering ```rosmsg show radar_msgs/RadarDetection```

## 4. Running Test Code

1. Uncomment test code lines in scripts/radar_parser.py (tagged: #TEST CODE)
2. Build the ROS project in the root folder of workspace(./cavs_ws) ```catkin_make```
3. Enable kvaser virtual CAN Bus (test program uses virtual channel '0')
4. In a new terminal window enter ```roscore``` to start the ROS Master 
5. In a new terminal window source the catkin_ws ```source ./cavs_ws/devel/setup.bash```
   - In the same terminal you can now run ```rosrun cavs_radar_example radar_parser.py``` to start up the ROS Node
6. In a new terminal window, start the CAN Bus sending program by entering ```python ./cavs_ws/documents/test_code/sender.py```
7. ROS Node radar_parser should begin to output recieved CAN Bus messages

### Important Nodes about Test Code
 - Test code uses a custom .dbc named test_radar.dbc (this is due to issues with CAVS_database.dbc)
 - The program is only sending data for the variable 'Radar_Target_Xpos' 
 - The ROS Node radar_parser needs to be run at folder above your workspace('../cavs_ws') to access the .dbc file 

