# Home-Automation-System

The thought behind this project idea is to build a home automation system using Google assistant
and node MCU. In this project we will be integrating our ThingSpeak channel with IFTTT (If This
Then That) which provides the google assistant service, so once we pass a specific command to
our google assistant then it will trigger a request and post a particular value to our ThingSpeak
channel. The ThingSpeak channel will act as a virtual database to which all our command requests
from the google assistant will be stored. For example, if we pass a command called “Turn on the
light” to our google assistant then a request will be triggered and a certain value will be stored in our 
ThingSpeak database and then from the thingSpeak database we can retrieve that certain value
which indicated the command to “turn on the light” and can be used to light up our hardware that is
connected through the Node mcu. Similarly, for other components we can give different requests
that will trigger the other components. The ThingSpeak channel has 8 fields which can be used to
connect different components.
