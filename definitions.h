/*
Defining libraries and variables and pins state
2022/9/19  7:25pm
*/


#ifndef definitions_h
#define definitions_h

#include "Arduino.h"
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <SoftwareSerial.h>

// SPI pins on Arduino Mega 
U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, /* CS=*/ 53, /* reset=*/ 49);
  
// RGB LED Pins *Common Anode RGB*
const byte r1=5, g1=4, b1=3, r2=6, g2=7, b2=8;

// Analog Value of the buttons *The values depends on the resistors that connected to the button*
const int buttonvalue[]={185, 312, 506, 238, 157};
//                       up  down select up&select  down&select
uint8_t shakeup=0, shakedown=0;// shake up&down states

int train_state;
int  recognizing, counter=0, sens=0;
int  led=13, touchsense = 21;
int q= -15, r=0, y=0, z=0;
uint8_t record_num=0; 
 // variables to use millis instead of delay
unsigned long PrevTime1=0, PrevTime2=0;
unsigned long CurrentTime1, CurrentTime2;
unsigned long CurrentTime3, PrevTime3=0; 

bool VoiceActive = false, firstlist=false, seclist=false, thirdlist=false, fourthlist=false;
bool happy_state=false;
bool voicetraining_command=false;

volatile const int interruptPin=2;
volatile int skip=1;


/* voice training variables  */
const char* numbers[33]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32"};
    
     
const char* categories[5]={ "Main Commands", "Chatting Commands", "Moving Commands", "Settings Commands", "Info"};    
       
const char* commands[25]={
"Hey Akno"
, "You Know What", "Goto", "Let's Play", "Who Are You", "Show Settings", "I Love You",
         
"I Hate You"
, "You Are Stupid", "I'm Sorry", "Nice Wheels", "Crazy", "Party Time",
        
"Go Right"
, "Go Left", "Forward", "Backward", "Spinning", "Do Problems", 
        
"Facial Expressions"
, "Battery Level", "Test LEDs", "Voice Training", "Test Motors", "Test Buttons"
                
};
 int uprange[4]={6, 12, 18, 24};
 int downrange[4]={0, 7, 13, 19};
 uint8_t categorie_item = 5; 
/* end of voice training variables*/          
int command_num=0, categorie_num=0; 
uint8_t next_page=0;

// motors pins
#define m1a 16
#define m1b 17
#define m2a 18
#define m2b 19
// Enable pins should always be HIGH or attached to vcc to work properly with the rest of the code
#define m1enable 14
#define m2enable 15

void defState(){
// 
    pinMode(interruptPin,INPUT); 
    
    pinMode(touchsense,INPUT); 
    
    pinMode(led,OUTPUT);
    
    pinMode(m1a,OUTPUT);
    pinMode(m1b,OUTPUT);
    pinMode(m2a,OUTPUT);
    pinMode(m2b,OUTPUT);
    pinMode(m1enable,OUTPUT);
    pinMode(m2enable,OUTPUT); 
       
    pinMode(r1,OUTPUT);
    pinMode(g1,OUTPUT);
    pinMode(b1,OUTPUT);
    pinMode(r2,OUTPUT);
    pinMode(g2,OUTPUT);
    pinMode(b2,OUTPUT);
    
    // all RGB pins set to HIGH because it's a common Anode RGB LEDS
    digitalWrite(r1, HIGH);
    digitalWrite(g1, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(r2, HIGH); 
    digitalWrite(g2, HIGH);
    digitalWrite(b2, HIGH);    

    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m1enable, HIGH);// always high
    digitalWrite(m2enable, HIGH); // always high    
    
}
// for converting the analog read into boolean with error value called "range"
bool comp(int v){
    sens = analogRead(A8);
  int range=8;// error ±8
  int high, low;
  high = sens+range;// set the value +8
  low = sens-range;// set the value -8
    if(v>low && v<high){
      return   true;       
    }    
    else return false;    
}
    


#endif
