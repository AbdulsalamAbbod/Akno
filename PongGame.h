/*
Pong Game header file :)
2022/9/19  7:25pm
 
*/


#ifndef PongGame_h
#define PongGame_h


#include "Arduino.h"
#include "moves.h"
#include "expressions.h"


// game boarders
void drawBoarders() {
    u8g2.setDrawColor(1);
    u8g2.drawFrame(0, 0, 128, 64);
}
  

void ponggame() {       
    const unsigned long PADDLE_RATE = 33;
const unsigned long BALL_RATE =23;
const uint8_t PADDLE_HEIGHT = 14;
const char* score[11]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
uint8_t player_score=0, cpu_score=0;
uint8_t hard_level = 1;

bool cheating=false;    
uint8_t ball_x = 64, ball_y = 32;
uint8_t ball_dir_x = 1, ball_dir_y = 1;
unsigned long ball_update;

unsigned long paddle_update;
const uint8_t CPU_X = 12;
uint8_t cpu_y = 16;

const uint8_t PLAYER_X = 115;
uint8_t player_y = 16;
 
    //uint8_t new_x;
    //uint8_t new_y; 
       
    unsigned long start = millis();    

    u8g2.clearBuffer();
    u8g2.sendBuffer();// be cautione here please!
    drawBoarders();   

    ball_update = millis();
    paddle_update = ball_update;    
    ball_x = 64, ball_y = 32;     

while(1) {
    bool update = false;
    unsigned long time = millis();

    static bool up_state = false;
    static bool down_state = false;
// you can change this with (digitalRead(x)==LOW) instead of analog buttona
    up_state |= (comp(buttonvalue[1]) == LOW);
    down_state |= (comp(buttonvalue[0]) == LOW);

    if(time > ball_update) {
       uint8_t  new_x = ball_x + ball_dir_x;
       uint8_t  new_y = ball_y + ball_dir_y;

        // Check if we hit the vertical walls                                    
           if(new_x==125 || new_x==2){   
                if(new_x==125){      
             u8g2.setDrawColor(0);  
      u8g2.setFont(u8g2_font_ncenB08_tr);        
      u8g2.drawStr(56, 15, score[cpu_score]);                                         
                  cpu_score++;                                 
            }                
         if(new_x==2){ 
            u8g2.setDrawColor(0);  
      u8g2.setFont(u8g2_font_ncenB08_tr);        
      u8g2.drawStr(72, 15, score[player_score]);                                      
               player_score++;    
               }   
                
   //   cheating :)          
       if(cpu_score==4 && ((new_x == CPU_X && new_y >= cpu_y && new_y <= cpu_y + PADDLE_HEIGHT)||(new_x>120))  ){
      //  lefteye();
        backward();
           delay(1100*skip);
              stop();
             cute();         
        LED1(0,255,155);
        LED2(0,255,155);              
        //   delay(3000*skip);     
     //   forward();
         //   delay(1000*skip);
        cheating=true;
              stop();
    }                             
                
           ball_dir_x = -ball_dir_x;
           new_x += ball_dir_x + ball_dir_x;                                                                                                                                                         
        }

        // Check if we hit the horizontal walls.
     if(new_y == 2 || new_y == 61 && cheating==false) {
         ball_dir_y = -ball_dir_y;
         new_y += ball_dir_y + ball_dir_y;                                            
           }

        // Check if we hit the CPU paddle
        if(new_x == CPU_X && new_y >= cpu_y && new_y <= cpu_y + PADDLE_HEIGHT && cheating==false) {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
                
        }

        // Check if we hit the player paddle
        if(new_x == PLAYER_X
           && new_y >= player_y
           && new_y <= player_y + PADDLE_HEIGHT && cheating==false)
        {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }
            u8g2.setDrawColor(1);  
      u8g2.setFont(u8g2_font_ncenB08_tr);        
      u8g2.drawStr(56, 15, score[cpu_score]);
      u8g2.drawStr(72, 15, score[player_score]);
        u8g2.setDrawColor(0);   
        u8g2.drawDisc(ball_x, ball_y, 2, U8G2_DRAW_ALL);
        u8g2.setDrawColor(1);
        u8g2.drawDisc(new_x, new_y, 2, U8G2_DRAW_ALL);
        ball_x = new_x;
        ball_y = new_y;

        ball_update += BALL_RATE;            
          
        update = true;
    }

    if(time > paddle_update&&(cheating==false)) {
        paddle_update += PADDLE_RATE;

        // CPU paddle
        u8g2.setDrawColor(0);
        u8g2.drawVLine(CPU_X, cpu_y, PADDLE_HEIGHT);
        const uint8_t half_paddle = PADDLE_HEIGHT >> 1;
         int error = random(5, 9-hard_level);
        if(cpu_y + half_paddle > ball_y+error) {
            cpu_y -= 1;
        }
        if(cpu_y + half_paddle < ball_y-error) {
            cpu_y += 1;
        }
        if(cpu_y < 1) cpu_y = 1;
        if(cpu_y + PADDLE_HEIGHT > 63) cpu_y = 63 - PADDLE_HEIGHT;
        u8g2.setDrawColor(1);
        u8g2.drawVLine(CPU_X, cpu_y, PADDLE_HEIGHT);

        // Player paddle
        u8g2.setDrawColor(0);
        u8g2.drawVLine(PLAYER_X, player_y, PADDLE_HEIGHT );
        if(up_state) {
            player_y -= 1;
        }
        if(down_state) {
            player_y += 1;
        }
        up_state = down_state = false;
        if(player_y < 1) player_y = 1;
        if(player_y + PADDLE_HEIGHT > 63) player_y = 63 - PADDLE_HEIGHT;
        u8g2.setDrawColor(1);
        u8g2.drawVLine(PLAYER_X, player_y, PADDLE_HEIGHT);
                   
        update = true;                    
    }  
                               
      // game over 
   if(player_score==5 || cpu_score==5 || cheating){
        u8g2.drawStr(32, 32, "GAME OVER!");   
            delay(2500*skip);
            //player win
            if(player_score==5){
               angry();
            LED1(255, 0,0);
            LED2(255, 0, 0);          
          delay(700*skip);
            backward();
            delay(1000*skip);
            hard_level=5;
                }
            //cpu win
            else if(cpu_score==5){
            LED1(0,255,155);
            LED2(0,255,155); 
                happy();
            right();
            delay(500*skip);
            left();  
           delay(500*skip);
                hard_level=2;
                }    
            stop();
            player_score=0;
            cpu_score=0;    
            break;
    }
    if(update){
        u8g2.sendBuffer();
    }
}}

    




#endif


