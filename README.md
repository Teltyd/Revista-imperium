Engineering of the Imperium Robot
=====================


This repository contains the process and its explanation of a self-driven vehicle participating in the WRO Future Engineers competition in the season 2023, made by the group of students Imperium.
## Content
* `NOMBRE ARCHIVO` This contains
* `NOMBRE ARCHIVO` This contains
* `NOMBRE ARCHIVO` This contains
* `NOMBRE ARCHIVO` This contains
* `NOMBRE ARCHIVO` This contains

## Introduction

 This robot is using C++ as its coding lenguage and that code is being sent into an arduino brain, specifically the ELEGO UNO R3, after the code is sent from the computer
 to the brain, the brain then acts according to the code, by following this code it effectively powers and receives signals from the camera, motor, servo motor and ultrasonic sensors, allowing the robot
 to cruise smoothly around the course that was set by the WRO, with the final version of the code the robot does it well, efficiently sending information back and forth between brain, sensors, cameras and engine to coordinate its movements accordingly.

 ## Planning

 We had to think about how to create this robot and how were were gonna do it, we started off by talking with each other, thinking about how it could be designed with efficiency in mind with what we had, despite not haing any 3D printers or special tools to maneufacture parts, we thought about what we had and then went to the board, out of this came out a 3D Model which can be seen in the magazine we designed and wrote, after we went to work, getting all the parts needed and started building our great robot.
 
 ## Challenges along the way

Our robot started off from a very basic idea, but became coplicated as it went. The robot had multiple flaws at the start, we couldn´t connect the wheels to the motor as we didn´t have the neccesary pieces, but we tried multiple ways at fixing the issue, our first attempt was to connect the wheels directly to the motors, but this didn´t work to what we needed as it left the wheels too close to the center of mass, making it extremely unstable when turning and moving forward, however we found a different way, if we had long screws we could pass them through the wheel and then attach them to the motor axles by using apoxy, but we quickly noticed that this would not work, as the motor spun it made the screws drill themselves out due to the friction from the chasis, since the wheels couldn´t spin, again, this was fixed by spacing he wheel from the chasis and then putting a screw shaft over the screw and epoxy, when it hardened it would make it so it would be impossible to unscrew itself, unless a lot of force was applied in a counter-clockwise motion.

With this challenge overcome it was not over, as we now had to finish the front part of the vehicle, figuring out how to make it so both front wheels, the ones that would be spun with the servo motor, moved correctly. We considered connect both wheels by long screws but remembered that when a vehicle is turning, the inward wheel moves slowewr than the outward wheel, if we did it this way then it would jam both wheels due to a variation in speed for each wheel, we overcame this by separating each wheel from the other with separate screws and gluing those screws with epoxy thus making them unable to unscrew themselves as a safety measure.

And now all we needed was to fix the cables and programming issues, the cables were simple enough, we just had to connect them to the adapters and or slots we had to put them in so that the brain could send power to each one and also send information back and forward between the sensors and cameras, effectively making the whole robot connected, programming on the other hand was, to say the least, not easy. A lot of the time we had a code which we thought would work but then the robot would not even move, dissappointing to say the least, but slowly and carefully we adjusted the code to the point where now we have a fully functioning robot!, after we added minor adjustments to make sure it would work properly, specially with round 2 which was the most challenging out of all.

With all of the challenges overcame we now had a functioning robot, ofcourse there would still be minor issues which would be fixed along the way, but the robot itself was ready, and that was what mattered.

## Assembly

We used many materials, from aluminum parts to plastic parts, but for our tech hardware we used arduino parts from kits, which we say were fitting to make our robot a reality, we started off with a black chasis, placing the ELEGO UNO R3 on the front of the chasis, right on top of it with screws and an aluminum base to keep it stable, next we placed a motor adapter on to the back of the chasis, soon after we placed the motor under the back of the chasis, aligning it with the wheel slots on the chasis, then using screws as a way to connect the wheels to the axles of the motor directly, using epoxy we glued them together. The ultrasonic sensors were only two, one was mounted on the right side of the chasis in the middle of it, and another one was connected to the left of the chasis in the same middle area. The servo motor was mounted a couple centimeters away from the rest of the chasis to make the vehicle longer and easier to turn, we used a transparent plastic piece to connect it to the chasis, then we used aluminum beams to secure it in place. An aluminum beam was used and connected to the servo motor axle, on this beam two C shaped aluminum pieces were used to connect the wheels to the beam, using screws to keep them in place and then epoxy to secure both of them, they could spin different from each other as they were not connected to each other directly, just to the beam, finishing the assembly process.

## Code

The code designed was specifically made for the robot, we measured the distances and the time in the course to make sure that the robot would complete the course accordingly, when the code was active, the robot would move forward until a timer ended, when this timer ended the robot would stop moving, according to calculations in the same place it started from, while the robot moved, the ultrasonic sensors were constantly sending information back to the brain, to be more specific they were sending the distance of the robot between the walls and the robot itself, with these measurements the robot would remain at the same distance from each wall from where it started, helping it keep itself in the right track until the end of round 1.

On round 2, the brain would also use the help of the camera, this camera would watch the field, until it spotted the color red or green, here it would turn depending on the color, and then after a certain time of detecting the color or when it went out of view it would turn back and go to its original lane, this would happen each time the robot detected color, the camera could also overwrite the ultrasonic signs sent by the ultrasonic sensors so that it could follow the instructions of the race, however as soon as the camera did not detect color anymore, the ultrasonic sensors would take over guiding the robot again.

## Testing

At the start the robot would crash a lot, like mentioned before, but it only took a couple days of texting until the robot would do whole laps without issues, we used the WRO mat on a wood base, however we lacked the black outer and inner walls, despite this we used boxes and other materiales to simulate this, thus giving us a similar-enough experience to how it would be like in the actual race, we also made red and green squares to go with it, thus giving us a good course to test our robot in.

## Parts used

The robot used the following:
* ELEGO UNO R3
* 4x Ardunio Kit yellow wheels
* Screws
* Bolts
* Epoxy
* Arduino Engine adapter
* Arduino kit motor
* Arduino kit double axle gearbox
* Cables
* Plastic chasis
* Aluminum Parts (Beams and others)

