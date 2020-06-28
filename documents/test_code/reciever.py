#CAN Bus sender program
import can
import cantools
import time

db = cantools.database.load_file('./test_radar.dbc')
example_message = db.get_message_by_name('ExampleMessage')
#print(example_message.signals)

bus = can.interface.Bus(bustype='kvaser',receive_own_messages=True, channel=0)
print("Ready to recieve CAN messages")

count = 0 
while (True):
	time.sleep(.250) #limit the recieving rate to test buffer ( sender is faster )
	message = bus.recv() #recieve the CAN message
	decoded_message = db.decode_message(message.arbitration_id, message.data)

	print("recv "+  str(count) + " X Pos: " + str(decoded_message['Radar_Target_Xpos'] )

	count = count + 1
