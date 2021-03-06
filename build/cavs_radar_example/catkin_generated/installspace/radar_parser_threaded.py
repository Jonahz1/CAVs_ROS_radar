#!/usr/bin/env python2
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of Willow Garage, Inc. nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Revision $Id$

import rospy
import cantools
import can
import sys
import os 
import threading

from std_msgs.msg import String
from radar_msgs.msg import RadarDetection

radar_message = RadarDetection() #define message as global variable, written to in handle_bus(), read in ROS node

#thread to handle CAN Bus and .dbc file extraction
def handle_bus():
    message = extract_dbc('./cavs_ws/dbc_files/CAVs_database.dbc','Radar_Target') #extract dbc info 
    bus = can.interface.Bus(bustype='kvaser', channel='vcan0')
    #message, db = extract_dbc('./cavs_ws/dbc_files/test_radar.dbc','ExampleMessage') #TEST CODE
    #bus = can.interface.Bus(bustype='kvaser',receive_own_messages=True, channel=0) #TEST CODE

    while not rospy.is_shutdown(): 
	#bus ready to recv data, this also gets data off bus buffer if it is there
	encoded_message = bus.recv(timeout=10) #recv is a blocking call, data will not update unless new data is on the BUS 
	if (encoded_message==None):
		print("Timeout!")
		sys.exit()					  
	print("Got message on CAN Bus!")
	decoded_message = db.decode_message(encoded_message.arbitration_id, encoded_message.data) #decoded_message is a python dictionary
	
        #update radar_message with new CAN data
	radar_message.position.x = decoded_message['Radar_Target_XPos']
	radar_message.position.y = 0
	radar_message.position.z = 0 
        radar_message.velocity.x = 0
        radar_message.velocity.y = 0
        radar_message.velocity.z = 0 

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
    pub = rospy.Publisher('radar_data', RadarDetection, queue_size=10) #defines topic name, message type, queue size
    rospy.init_node('radar_parser', anonymous=True) #defines node unique node name 
    rate = rospy.Rate(10) # 10hz / 100ms publishing rate

    t1 = threading.Thread(target=handle_bus())
    t1.start()
        
    #setup position
    radar_message.position.x = 0
    radar_message.position.y = 0
    radar_message.position.z = 0 #will always be zero (data only give x & y position) 
    #setup velocity
    radar_message.velocity.x = 0
    radar_message.velocity.y = 0
    radar_message.velocity.z = 0 #will always be zero (data only give x & y velocity)


    counter = 0
    while not rospy.is_shutdown():

        rospy.loginfo(counter) #logs info as [INFO]
	counter = counter + 1 
        pub.publish(radar_message) #actually publishes message to topic radar_data
        rate.sleep() #regulates publishing rate 

if __name__ == '__main__':
    try:
        radar_parser()
    except rospy.ROSInterruptException:
        pass
