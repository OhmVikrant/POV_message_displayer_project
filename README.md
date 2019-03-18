POV Globe AND Message Displayer
(Parent project- 3D propeller Clock)

(Project paricipants--  Vikrant Dey(EE-1st yr), Priyanshu Singh Somvanshi(EE-1st yr), Himanshu Badala(PI-1st yr)
Mentor-- Archit Dangayech(EE-3rd yr)
IIT Roorkee)



First go through the following. For implementation follow the instructions given in the doc ‘STEPS’.


We followed the following tutorial https://www.instructables.com/id/POV-Globe/ and it worked for most part!! The project basically uses persistence of vision to create an optical illusion wherein LEDs turning on and off in at specific durations create a definite pattern when rotated at high speed.
The Code:
Since it was our first encounter with Arduino we had to rely heavily on online tutorials and examples. The following tutorial series might give a brief overview of Arduino : https://www.youtube.com/playlist?list=PLA567CE235D39FA84 .
Now coming back to the code, since this project involves use of HC595 shift registers, it is of utmost importance that we learn their use. www.arduino.cc/en/Tutorial/ShiftOut : This link teaches their application as well as allows us to test the complete the circuit on breadboard.

Drawing the globe:
The blog on that we followed  ( https://www.instructables.com/id/POV-Globe/  ) contains all the information to draw a globe (or any picture for that matter). Due to time constraints, we stuck to globe only but will display other images in the future, if time permits.

Message displayer:
To display any message we used 5 red LEDs so that they do not overlap with the globe formed by blue LEDs. Also, we attached the red LEDs on a perf board before fixing them on the ring so that the message appears straight and is not distorted due to curvature of ring.
As far as code is concerned, the following link immensely helped us : https://maker.pro/arduino/projects/arduino-pov-display 
Just skip the hardware part  and take the code from the site. The code basically creates an array for all 26 alphabets and some special characters. The array corresponding to each character contains 5 five elements which allow us to create 5X5 grid. Each element of an array has to be converted into its binary form wherein 1s will indicate the time when LED is turned on. With little effort arrays corresponding to digits can also be created.
