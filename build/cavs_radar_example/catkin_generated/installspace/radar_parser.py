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

## Simple talker demo that published std_msgs/Strings messages
## to the 'chatter' topic

import rospy
import cantools
from std_msgs.msg import String
from radar_msgs.msg import RadarDetection

def talker():
    pub = rospy.Publisher('radar_data', RadarDetection, queue_size=10) #defines topic name, message type, queue size
    rospy.init_node('radar_parser', anonymous=True) #defines node unique node name 
    rate = rospy.Rate(10) # 10hz / 100ms publishing rate

    #extract .dbc information 
    rospy.loginfo("Extracting .dbc information.")

    message = RadarDetection()

    #setup position
    message.position.x = 'oops wrong type'
    message.position.y = 0
    message.position.z = 0 #will always be zero 
   
    #setup velocity
    message.velocity.x = 0
    message.velocity.y = 0
    message.velocity.z = 0 #will always be zero 

    #setup detection id
    message.detection_id = 0 #defaults to zero

    #setup amplitude
    message.amplitude = 0 

    while not rospy.is_shutdown():
        rospy.loginfo(message) #logs info as [INFO]
        pub.publish(message) #actually publishes message to topic radar_data
        rate.sleep() #regulates publishing rate 

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
