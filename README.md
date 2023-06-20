# Akno 1.1v
AKNO is a smart, kind, and cute robot
made with love and wires.

By Abdulsalam Abbod Shihab 2022/9/24, 6:30pm

Akno is a smart robot with voice recognition
and facial expressions.
It reacts with voice commands with 25 voice command
and it has 15 different facial expression
on 128*64 lcd display via SPI, and the main 
AKNO'S brain is the Arduino MEGA 2560
Powered by two 18650 3.7v 2000mAh batteries.
With two common Anode RGB LEDs one in the front
and one in the back of the robot, with 3 push buttons 
for a varies functionalities.
/**/

===========================================

/*Features*/
Akno support's more than 250 voice command (25 of them is already  in use at that version)

15 different facial expression with smoth animation
(happy, sad, angry, upset, normal, cute, suspicious, iam, youmademe, wonder, downeye, righteye, lefteye, upeye, blink) plus two RGB LEDs effects.

6 different moving pattern (right, left, forward, backward, spinning, doproblems)

Akno support's game mode (PongGame) you can play 
with him.

You can add more features if you're familiar with c/c++.
/**/

===========================================


/* NOTICE CAREFULLY*/
Please notice all buttons connected to analog pin 
with resistors, so you should consider
that if you want to change the buttons into digital pin.

All enable pins of the motor driver which (l293d) ic
at high state, or you can just attach it to 5v.

I used common Anode RGB LEDs at this version of
AKNO, so if you want to use common Cathode LEDs
you should make changes at :
expressions.h/(line:250&line:262)/(LED1&LED2) functions by 
Just deactivate the marked three lines.
/**/

===========================================


/*Updates*/
Stay tooned for updates, and if you're interested
in contributing at this project contact me
abdulsalamabbod@gmail.com
/**/

This is the the worst code I've ever written, but it works :)

Thanks for supporting 







little secret : I made this entire robot from my smartphone 👽


