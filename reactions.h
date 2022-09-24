/*
Reactions to voice Commands.
2022/9/23      11:09:54 pm
*/


#ifndef reactions_h
#define reactions_h

#include "Arduino.h"
#include "moves.h"




// load main list    (1st)
void heyakno_reaction(){
     right();
            delay(300*skip);
            stop();          
     switch(random(3)){
      case 0: wonder();  break;
      case 1: righteye(); delay(800*skip);  break;
      case 2: lefteye(); delay(800*skip); break;
            }
}

// load chatting list  (2nd)
void youknowwhat_reaction(){   
      right();    
       delay(600*skip);
       stop();
       wonder();
}

// load goto list
void goto_reaction(){
        right();
            delay(200*skip);
            stop();
            wonder();
}


void youarestupid_reaction(){

        sad();
           LED1(255, 0, 0);
           LED2(255, 0, 0);
            backward();
              delay(2000*skip);           
            stop();
              delay(1100*skip);
            upset();
              delay(300*skip);
}

 
void partytime_reaction(){

       LED1(100, 255, 255);
            LED2(100, 255, 255);
            happy();
            forward();
            delay(700*skip);
            right();
            delay(500*skip);
            backward();
            delay(800*skip);
            for(int i = 0; i < 3*skip; i++) {
                right();
                delay(400*skip);
                left();
                delay(400*skip);
            }
            forward();
            delay(700*skip);
            right();
            delay(500*skip);
            backward();
            delay(800*skip);
            stop();
}

void goright_reaction(){

       right();
            righteye();
             delay(2000*skip);
            stop();
}

void goleft_reaction(){
       left();
       lefteye();
         delay(2000*skip);
       stop();
}

void gobackward_reaction(){
       backward();
        delay(1500*skip);
       stop();

}

void nicewheels_reaction(){    
  LED1(100,200,255);
  LED2(100,200,255); 
             cute();
            right();
            delay(2000*skip);
            left();  
           delay(2000*skip);           
           stop();

}

void letsplay_reaction(){
    ponggame();
}


void doproblems_reaction(){     
            right();
             delay(600*skip);
            forward();
             delay(1300*skip);
            angry();
             delay(900*skip);
            normal();
            right();
             delay(700*skip);
            backward();
             delay(1300*skip);
            happy();
             delay(900*skip);
}

void whoareyou_reaction(){
           iam();
             delay(4500*skip);
            happy();
             delay(1100*skip);
}


// load setting list
void showsettings_reaction(){
    LED1(0,0,255);
     LED2(0,0,255); 
    delay(600*skip);
     LED1(0,255,255);
     LED2(0,255,255); 
}


void iloveyou_reaction(){
     LED1(255,0,255);
     LED2(255,0,255); 
      cute();
      right();
       delay(400*skip);
      left();  
       delay(400*skip);           
      stop();
}


void ihateyou_reaction(){ 
      
         LED1(255,0,255);
         LED2(255,0,255); 
              sad();       
           delay(1000*skip);
           right();
            delay(1000*skip);
            forward();  
           delay(1200*skip);           
           stop();
}


void crazy_reaction(){
    // do crazy

}

void goforward_reaction(){
    forward();
    delay(1000*skip);
    stop();
}


void spining_reaction(){
      right(); 
    delay(3000*skip); 
    left();
    delay(3000*skip); 
    stop();       
}


void expressions_reaction(){
    delay(1300*skip);
    happy();   delay(1300*skip);
    sad();   delay(1300*skip);
    angry();   delay(1300*skip);
    cute();    delay(1300*skip);
    wonder();
    lefteye();  delay(1300*skip);
    righteye();   delay(1300*skip);
    upset();     delay(1300*skip);
    normal();    delay(1300*skip);
    close();     delay(1300*skip);
    suspicious();  delay(1300*skip);
    downeye();     delay(1300*skip);
    upeye();       delay(1300*skip);
    iam();         delay(1300*skip);
    youmademe();   delay(1300*skip);          

}


void imsorry_reaction(){
      LED1(255,100,0);
     LED2(255,100,0); 
            suspicious();
             backward();
            delay(1100*skip);                    
           stop();

}


void battreylevel_reaction(){

    // Soon as there is a moon!
}


void colortest_reaction(){
    for(int i=0;i<256;i++){
         LED1(i,0,0);
         LED2(i,0,0); 
         delay(11);
}
   for(int i=0;i<256;i++){
         LED1(0,i,0);
         LED2(0,i,0); 
        delay(11);
}
  for(int i=0;i<256;i++){
         LED1(0,0,i);
         LED2(0,0,i);
        delay(11); 
}
     for(int i=0;i<256;i++){
         LED1(i,i,i);
         LED2(i,i,i);
        delay(11);
}
    
    }

void testmotors_reaction(){
    right(); 
    delay(1000*skip); 
    left();
    delay(1000*skip); 
    forward();
    delay(1000*skip); 
    backward();
    right(); 
    delay(2500*skip); 
    left();
    delay(2500*skip); 
    stop();                          
}

void testbuttons_reaction(){
      
}

void voicetraining_reaction(){
    voicetraining_command=true;
}









#endif

