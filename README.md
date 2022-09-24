# Akno 1.1v
Akno is a smart, kind, and cute robot
made with love and wires.

By Abdulsalam Abbod Shihab 2022/9/24, 6:30pm

Akno is a smart robot with voice recognition
and facial expressions.
It reacts with voice commands with 25 voice command
and it has 13 different facial expression
on 128*64 lcd display via SPI, and the main 
Brain of Akno is the Arduino MEGA 2560
Powered by two 18650 3.7v 2000mAh batteries.
With two common Anode RGB LEDs one in the front
and one in the back of the robot.
/**/

/* NOTICE CAREFULLY*/
Please notice all buttons connected to analog pin 
with resistors in parallel, so you should consider
that if you want to change the buttons into digital

All enable pin or the motor driver which (l293d) ic
at high state, or you can just attach it into 5v.

I used common Anode RGB LEDs at this version of
Akno, so if you want to use common Cathode LEDs
you should make changes at :
expressions.h/(line:250&line:262)/(LED1&LED2) functions by 
Just deactivate the three lines.

/**/


/*Updates*/
Stay tooned for updates, and if you interested
in contributing at this project contact me
abdulsalamabbod@gmail.com
/**/

Thanks for supporting 


