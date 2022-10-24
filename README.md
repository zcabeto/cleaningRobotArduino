# cleaningRobotArduino

My Technology A Level project could have been anything but I chose specifically sonmething to test my computer science knowledge too via the use of Arduino coding. 
I reached the project idea of a robot that scurries around the floor cleaning in ways something like a roomba could not with the projected owner being a cafe. The robot would pick up food and other objects off the floor.
I had to write preliminary code that could allow the robot to function properly but also appropriately avoid obstacles such as chair and table legs. For this function I combined servo motor wheels with Ultra Violet sensor 'eyes'.
Below is written the descriptions relating to each piece of code that I wrote in my final submitted project folder...

      motorTesting.cpp / directionalControlTesting.cpp / dialDirectionControl.cpp:
With a rough scope on how my chosen product might pickup, store, and dispose of debris, I need to begin analysing the method of movement I will use.
Cafés have many tables and chairs that will need to be avoided, as well as any people who may be walking around, these will need to be avoided. While avoiding these obstacles the product must be able to clean around and under tables, as well as in open space.
To get the movement to work I had to code the controller for them. I did this using an Arduino microcontroller that I wrote code for in C++
For testing reasons, I constructed the code using a previously made LED shield in which I could use different lights to signify different outputs. I could also use the buttons and dial on the shield for inputs.
I coded the system so that it one button could be for forward and one button for backward, then the dial (A1) could pinpoint the direction of the movement. The lights represent movement as noted by the comments. Once I had got this to work, I could build the system that would actually power a motor instead of lights.
The system connected the shield to the Arduino via Breadboard wires and also soldering the battery and motors to the shield. To test the system I had put together I wrote some test code for one motor as shown. At first the code could not run however I soon learnt it was due to not having enough power; once a 9V battery was connected, the system ran smoothly. With the circuitry working, I can take note of the parts required and save creating the final code until I have built the chassis.


      US_sensorTesting.cpp:
Initial trial coding allowed me to grasp the basics of coding with the Ultrasonic Sensor


      sensorTriangulation.cpp:
As discussed on the previous few pages, two sensors could be used to triangulate a position of an obstacle, this is called a position fix. For this I am taking inspiration from VOR Navigation aids in aviation. How it works is two sources send signals to a receptor – the receptors position can be known by working out where the signals should intercept. In aviation, this is done using directional interceptions (shown right), for this system, an interception would be found between the distances found by each ultrasonic sensor. According to the product information, the angular range of this sensor is 15 degrees each way, therefore any distance found could be anywhere in that range. We can use this in the method described above and illustrated right.
To test this I thought it best to make a rig to mount the sensors on. This way I can work out whether this is a feasible method of position fixing. Quick testing of code to the left showed the max distance the sensor could see was 3.4m, so I did a short plan of different angles of the sensors to use. I would say that 2m is more than enough space for the bot to react to an obstacle and move accordingly. Additionally, larger angles will lead to a larger difference in detected distances (therefore being more accurate), so I believe 50 degrees would be sufficient, at least for the testing.


      sensorAreas.cpp
A way which we can mitigate the effect of the limited accuracy of ultrasonic sensors is to instead use their area of detection to pin point positions. What is meant by this is that two sensors pointing across each other will have an area in which they intercept. By knowing which region an object is (shown below), the bot will know enough position information about the obstacle (does not need exact relative position, just whether it is on right left or centre), while it uses position detection from the sensors as a rough telling of how far away the object is – likely being characterised into regions too (somewhat shown by arc lines drawn). This should solve the problems with the previous idea.
How this would be used would be:
• Object detected at 1.2m by the right sensor (left area zone seen by right sensor only) (green)
    • Veer right slightly
• Object detected at 1.2m by the left sensor (right area zone seen by left sensor only) (blue)
    • Veer left slightly
• Object detected at 1.2m by both sensors (centre zone between sensors seen by both) (red)
    • Larger turn to the side for full avoidance
• Object detected at more than 1.2m
    • No action required
I believe this would be very good at ensuring the sensors had a full view of the surroundings, or at least a much as might be necessary. However, unlike what I had mentioned when doing loose testing on the left, much physical (and now YouTube as I do not have access to the sensors now) research as presented just how inaccurate the ultrasonic sensors are and how their readings fluctuate too much to give concrete distances.
This opens up the problem that is when there are two objects, one in the blue area and one in the green, that are about the same distance away from the sensors. I believe this occurrence would not be uncommon for a café as most of the obstacles would be chairs – which have two legs that could do just this. This would result in the program thinking there was only one object and that it was in the red area – meaning the product might turn to the side only travel directly into one of those obstacles. At this present time, the only simple solution I can think of without adding more sensors would be to ensure the bot is travelling quite slowly. When turning away to avoid the object that is believed to be in the red zone, the sensors will eventually have only one of the sensors see an object, at which point it will find out that there is only one object now in its path and that it is off to the side and not straight ahead.
