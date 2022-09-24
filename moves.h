/*
Moves header file
2022/9/19  7:25pm

*/


#ifndef moves_h
#define moves_h

#include "Arduino.h" 
#include "definitions.h"

void backward();
void right();
void left();
void stop();
void forward();


void hanging(){

    //randomSeed(analogRead(A15));
   int rand = random(8);// choose a random action move
    switch(rand){
        case 0:
         right();
      delay(300*skip);  
          stop();      
        break;
        
        case 1:    
    left();
      delay(500*skip);
    stop();              
        break;
        
        case 2:
    forward();
      delay(300*skip);
    stop();      
       break;
        
        case 3:
    backward();
      delay(300*skip);
    stop();     
       break;
        
          case 4:
    right();
      delay(2000*skip);
    stop();  
       break;
        
            case 5:
    left();
      delay(2000*skip);
    stop();            
       break;
        
            case 6:
        forward();
        delay(1200);
        stop();
       break;  
        
            case 7:
         backward();
        delay(1000*skip);
       break;                        
    
    default : break; 
        
    }
}


void forward(){    
digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH);

}

void backward(){
  
digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW);

}

void right(){
  
digitalWrite(m1a, LOW);
digitalWrite(m1b, HIGH);

      
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH);

}

void left(){
   
digitalWrite(m1a, HIGH);
digitalWrite(m1b, LOW);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW);
}

void stop(){       
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);      
}





#endif

