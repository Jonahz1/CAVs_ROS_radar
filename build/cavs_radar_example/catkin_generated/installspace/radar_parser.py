#!/usr/bin/env python2

#Author: Jonah Gandy 
#NetID: jtg390
#email: jonahgandy@gmail.com
#source 1: https://pypi.org/project/cantools/
#source 2: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29

import rospy
import cantools
import can
from radar_msgs.msg import RadarDetection

#supporting function to extract information from .dbc file 
def extract_dbc(DBC_FILE_PATH, MESSAGE_NAME):
    rospy.loginfo("Extracting .dbc information.")
    try: 
	db = cantools.database.load_file(DBC_FILE_PATH) #load the dbc file
	temp_message = db.get_message_by_name(MESSAGE_NAME) #get radar signal by name
	rospy.loginfo("Extracting .dbc data complete.") #status message
    except: 
	rospy.logerr("Failed to extract .dbc information. Exiting ROS node.") #status message
	sys.exit() #shutdown ROS node

    return temp_message, db #return message and instance of dbc class 

def radar_parser():
    #ROS node setup 
    pub = rospy.Publisher('radar_data', RadarDetection, queue_size=10) #defines topic name, message type, queue sizes
    rospy.init_node('radar_parser', anonymous=True) #defines node unique node name 
    rate = rospy.Rate(10) # 10hz / 100ms publishing rate

    message = extract_dbc('./cavs_ws/dbc_files/CAVs_database.dbc','Radar_Target') #extract dbc info /comment out for TEST CODE
    bus = can.interface.Bus(bustype='kvaser', channel='vcan0') #setup bus for recieving data /comment out for TEST CODE

    #message, db = extract_dbc('./cavs_ws/dbc_files/test_radar.dbc','ExampleMessage') #TEST CODE
    #bus = can.interface.Bus(bustype='kvaser',receive_own_messages=True, channel=0) #TEST CODE

    #init message
    radar_message = RadarDetection()

    counter = 0 #counter to keep track of publisher runtime

    #publishing loop
    while not rospy.is_shutdown():
	#Recieve CAN Msg
	encoded_message = bus.recv() #get data off bus recieve buffer 
	rospy.loginfo("Got message on CAN Bus") #logs for recieving CAN bus message

	#Decode message
	decoded_message = db.decode_message(encoded_message.arbitration_id, encoded_message.data) #decoded_message is a python dictionary
        rospy.loginfo(counter) #logs counter to terminal
	counter = counter + 1 

	#Update message
	radar_message.position.x = decoded_message['Radar_Target_Xpos']
	radar_message.position.y = decoded_message['Radar_Target_Ypos'] #comment this line out for TESTING
	radar_message.position.z = None #comment this line out for TESTING
	radar_message.velocity.x = decoded_message['Radar_Target_Vx'] #comment this line out for TESTING
	radar_message.velocity.y = decoded_message['Radar_Target_Vy'] #comment this line out for TESTING
	radar_message.velocity.z = None #comment this line out for TESTING

	#Publish message
        pub.publish(radar_message) #publishes message to topic radar_data
        rate.sleep() #regulates publishing rate 

if __name__ == '__main__':
    try:
        radar_parser()
    except rospy.ROSInterruptException:
        pass
