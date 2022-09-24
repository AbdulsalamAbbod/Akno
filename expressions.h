/*
Expression header file, contains all facial expressions animation and RGB effects 

*/

#ifndef expressions_h
#define expression_h

#include "Arduino.h"
#include "definitions.h"

// eye close expression
void close(){
    u8g2.clearBuffer();
        
  u8g2.drawRBox(5,19,55,18, 6);         
  u8g2.drawRBox(67,19,55,18,6);
    u8g2.setDrawColor(0);
    
    u8g2.drawBox(5,1,55,18);         
   u8g2.drawBox(67,1,55,18);
    
    u8g2.setDrawColor(1);
    u8g2.sendBuffer();
    
}
    
// normal expression 
void normal(){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);
    u8g2.sendBuffer();
    happy_state=false;
}

void blink(){
  if((CurrentTime1 - PrevTime1)>150){
 
  normal();     
         
    PrevTime1=CurrentTime1;  
   }  
      
 if((CurrentTime2 - PrevTime2)>1900){
   close();        
        delay(50);
    PrevTime2=CurrentTime2;           
     }
}

void sad(){   
  for(int i=0;i<=15;i+=3){
    u8g2.clearBuffer();
        
    u8g2.drawRBox(8,18,50,29, 9);         
    u8g2.drawRBox(70,18,50,29,9);    
      u8g2.setDrawColor(0);    
   //                    14             25
    u8g2.drawTriangle(3, 14, 64, 14, 3, 21+i);    
    u8g2.drawTriangle(68, 14, 124, 21+i, 124, 14);  
  //                               25        
      u8g2.setDrawColor(1);
             
    u8g2.sendBuffer();    
        }
}

// upset expression 
void upset(){
    if(!happy_state){
   u8g2.clearBuffer();
    
  u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);    
   u8g2.setDrawColor(0); 
     
  u8g2.drawBox(8,q,50,35);         
  u8g2.drawBox(70,q,50,35); 
    u8g2.setDrawColor(1); 
    
    u8g2.sendBuffer();
// to make the smoth animation
    if(q<=-7){  q+=3;  }
   }
}


// wonder expression with smoth animation
void wonder(){   
    u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);
        
    for(int i=1;i<=10*skip;i+=4){
      u8g2.clearBuffer();
  u8g2.drawRBox(8,12+i,50,35-i, 9);         
  u8g2.drawRBox(70,12,50,35,9);
    u8g2.sendBuffer(); 
       }       
    delay(1600*skip);
    
        
   for(int i=1;i<=10*skip;i+=4){
     u8g2.clearBuffer();
  u8g2.drawRBox(8,22-i,50,25+i, 9);         
  u8g2.drawRBox(70,12+i,50,35-i,9);    
    u8g2.sendBuffer();
    }
     delay(1600*skip);
}



// happy expression with smoth animation 
void happy(){
  for(int i=62*skip;i>58;i-=3){
    u8g2.clearBuffer();
    
  u8g2.drawRBox(8,12,50,35, 11);
  u8g2.drawRBox(70,12,50,35,11);
   u8g2.setDrawColor(0); 
      
    u8g2.drawDisc(33, i, 38, U8G2_DRAW_ALL);
//                33  62 38   draw all    
    u8g2.drawDisc(95, i, 38, U8G2_DRAW_ALL);     
    
  u8g2.setDrawColor(1);
  
    u8g2.sendBuffer();
   }
    happy_state=true;
}


void cute(){
for(int i=0*skip;i<=2;i+=2){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8,12,50,35, 12);
  u8g2.drawRBox(70,12,50,35,12);
   u8g2.setDrawColor(0);       
    u8g2.drawDisc(30, 66-i, 40, U8G2_DRAW_ALL);
//                33  62 38   draw all    
    u8g2.drawDisc(98, 66-i, 40, U8G2_DRAW_ALL);     
 //               95   62 38   
  u8g2.setDrawColor(1);  
    u8g2.sendBuffer();
   }

    happy_state=true;
}


// angry expression
void angry(){
    for(int i=0;i<=15;i+=3){
    u8g2.clearBuffer();
  u8g2.drawRBox(8,18,50,29, 9);         
  u8g2.drawRBox(70,18,50,29,9);
    u8g2.setDrawColor(0);    
    u8g2.drawTriangle(3, 14, 64, 18+i, 124, 14);
    u8g2.setDrawColor(1);     
    u8g2.sendBuffer(); 
        }   
}
// string expression
void iam(){    
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(5, 15, "My name is Akno");
    u8g2.drawStr(5, 30, "Nice to meet you :)");
    
    u8g2.sendBuffer();
}

// string expression
void youmademe(){

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB08_tf); 
    u8g2.drawStr(1, 15, "The person who made me");
    u8g2.drawStr(1, 30, "Is Abdulsalam :) ");
    u8g2.drawStr(1, 45, "He is such a great person");
    
    u8g2.sendBuffer();

}

void suspicious(){
    for(int i=0;i<=10;i+=3){
    u8g2.clearBuffer();
    u8g2.drawRBox(8,12,50,20, 9);         
    u8g2.drawRBox(70,12,50,20,9);    
    u8g2.setDrawColor(0);    
    u8g2.drawTriangle(12, 12, 64, 12+i, 107, 12);          
    u8g2.setDrawColor(1);     
    u8g2.sendBuffer();     
        }   
}

void downeye(){
 
   close();
    delay(120);
  for(int i=0;i<=12;i+=4){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8,22+i,50,21, 9);         
  u8g2.drawRBox(70,22+12,50,21,9);
    u8g2.sendBuffer();
       } 
}

void righteye(){
        close();
    delay(120);
  for(int i=0;i<=8;i+=4){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8-i,17,50,27, 9);         
  u8g2.drawRBox(70-i,17,50,27,9);
    u8g2.sendBuffer();
       }
}

void lefteye(){
  close();
    delay(120);
  for(int i=0;i<=8;i+=4){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8+i,17,50,27, 9);         
  u8g2.drawRBox(70+i,17,50,27,9);
    u8g2.sendBuffer();
     }  
}
   
void upeye(){
   close();
    delay(120);
  for(int i=0;i<=12;i+=4){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8,12-i,50,25, 9);         
  u8g2.drawRBox(70,12-12,50,25,9);
    u8g2.sendBuffer();
       }
} 



// Front RGB effect    
void LED1(int r, int g, int b){
 /*Decative this three lines if you use common-cathode RGB LED */
   r= 255-r;
   g= 255-g;
   b= 255-b;
/* end */
    analogWrite(r1,r);
    analogWrite(g1,g);
    analogWrite(b1,b);
}

// Back RGB effect
void LED2(int r, int g, int b){ 
/*Decative this three lines if you use common-cathode RGB LED */
   r= 255-r;
   g= 255-g;
   b= 255-b;
/* end */  
    analogWrite(r2,r);
    analogWrite(g2,g);
    analogWrite(b2,b);
}
   
void handshake(){
// for detecting the shake up
  if(comp(buttonvalue[0])){
        shakeup++;
          }
    
// for detecting the shake down
    if(comp(buttonvalue[1])){
        shakedown++;
          }
// if the hand is shaked be happy :)
   if(shakeup>1 && shakedown>1){    
            LED1(0,255,155);
            LED2(0,255,155);    
                cute();
        delay(1000*skip);
            right();
            delay(500*skip);
            left();  
           delay(500*skip);
        stop();
        shakeup=0;// reset the shake state
        shakedown=0;
      }

}





#endif