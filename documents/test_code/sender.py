#CAN Bus sender test program
#Jonah Gandy 
#NetID: jtg390
#source: https://pypi.org/project/cantools/

import can
import cantools
import random
import time

db = cantools.database.load_file('./test_radar.dbc') #only works with this specific file currently 
example_message = db.get_message_by_name('ExampleMessage')

#set recieve_own_message to True for local virtual canbus
bus = can.interface.Bus(bustype='kvaser',receive_own_messages=True, channel=0)
bus.flush_tx_buffer() #overflow flush

#for demonstration purposes, xPos is encoded into the CAN signal
print("Sending 100 CAN Messages")

for i in range(0,99):
	xPos = random.randrange(250,270)
	data = example_message.encode({'Radar_Target_Xpos': xPos , 'Enable': 1, 'Radar_Target_Ypos':250.1}) #encode message using example message from dbc file 
	message = can.Message(arbitration_id=example_message.frame_id, data=data) #ready CAN message
	bus.send(message) #send the CAN message

	decoded_message = db.decode_message(message.arbitration_id, message.data) #checking sent data
	time.sleep(0.100) #delay to prevent bus overflow


