/*

Akno source code v1.1

By Abdulsalam Abbod

Please make sure to read README.md file first
to make sure your Akno works fine.

email : abdulsalamabbod@gmail.com
telegram : @Jstpi

2022/9/2  10:48pm friday


"Akno made with love, so don't treat him bad :)"

*/

#include "VoiceRecognitionV3.h"
#include "definitions.h"
#include "PongGame.h"
#include "voice_commands.h"
#include "moves.h"
#include "reactions.h"

// Voice Recognition pins connection
VR myvr(10, 11); // Rx => 11, Tx => 10
//      10  11

uint8_t records[7];
uint8_t buf[64];


void ponggame();


void setup() {
    Serial.begin(115200);
    
    myvr.begin(9600);
    myvr.setIOMode(3);
    attachInterrupt(digitalPinToInterrupt(interruptPin), listening, RISING);

    defState();

    load_main_commands();

    u8g2.begin();
    u8g2.clearBuffer();
    LED1(0, 155, 255);
    LED2(100, 255, 0);
    close();
    delay(600); // 600
    normal();
    delay(200); // 200
    close();
    delay(150); // 150
    normal();
    delay(400); // 400
    hanging();
    skip = 1;
 
}



void loop() {
    LED1(0, 155, 255);
    LED2(100, 255, 0);
    CurrentTime1 = millis();
    CurrentTime2 = millis();
    CurrentTime3 = millis();
    u8g2.clearBuffer();
    stop();
    skip = 1;
    

    recognizing = myvr.recognize(buf, 50);
     
// when voice active is true reset IO pins of the voice recognition module to make a custom pulse
    if(VoiceActive == true) {
        myvr.resetIO(0);
        VoiceActive = false;    }
// random actions every 4 seconds
    if((CurrentTime3-PrevTime3) > 5000) {
        hanging();
        PrevTime3=CurrentTime3;
    }
      

    if(counter == 150) {  counter = 180;  }
// upset when long time passes
    if(counter > 150) {
      upset();              
        counter -= 1;
        if(counter == 150) {  counter = 0;  }
    }
  // blink when not upset (normal mode)
    else {   blink();
             q = -15;                
             counter++; 
        Serial.println(analogRead(A8));   }
 // Enter voice training mode if (select&up)or(select&down) button is pressed at the se time
  if(comp(buttonvalue[3])||comp(buttonvalue[4])||voicetraining_command){
        train_voice();
      voicetraining_command=false;     
         close();
    delay(600); // 600
    normal();
    delay(200); // 200
    close();
    delay(150); // 150
    normal();
    delay(400); // 400
    hanging();
        }
   
     handshake();// check if hand is shaked
   
// check if there's voice command active
    if(recognizing > 0) {
// skip variable is to make all delay =0 when voice command is comming, and let the delay normal when voice command is not active 
        skip = 1;
        switch(buf[1]) {

            case heyakno:
            heyakno_reaction();
            if(!firstlist) {
                myvr.clear();
                load_main_commands();
            }
            break;
            
                 case youknowwhat:
            youknowwhat_reaction();
            if(!seclist) {
                myvr.clear();
                load_chatting_commands();
            }
            break;

            case gotoo:       
           goto_reaction();
      
            if(!thirdlist) {
                myvr.clear();
                load_moving_commands();
            }
            break;

          case youarestupid:            
        youarestupid_reaction();
            break;

            case partytime:
         partytime_reaction();
            break;


            case goright:
         goright_reaction();
            break;

            case goleft:
         goleft_reaction();
            break;

            case gobackward:
         gobackward_reaction();
            break;

            case nicewheels:
       nicewheels_reaction();
            break;

            case letsplay:
            letsplay_reaction();
            break;

            case doproblems:
          doproblems_reaction();
            break;

            case whoareyou:
         whoareyou_reaction();
            break;
            
               case iloveyou:
         iloveyou_reaction();
            break;
            
               case ihateyou:
         ihateyou_reaction();
            break;
            
              case imsorry:
         imsorry_reaction();
            break;
            
             case crazy:
         crazy_reaction();
            break;
            
                  case goforward:
         goforward_reaction();
            break;
            
                 case spining:
         spining_reaction();
            break;
            
                 case expressions:
         expressions_reaction();
            break;
            
            
                  case battreylevel:
         battreylevel_reaction();
            break;
            
              case colortest:
         colortest_reaction();
            break;
            
               case voicetraining:
         voicetraining_reaction();
            break;
            
            
            
              case testmotors:
         testmotors_reaction();
            break;
            
            
              case testbuttons:
         testbuttons_reaction();
            break;
                                    
                        
        case showsetting:
            showsettings_reaction();
             if(!fourthlist) {
                myvr.clear();
                load_settings_commands();
                  }
            break;
            
        default: break;

        }


    }
}


// interrupting when voice command is comming
void listening() {
    skip = 0;// make skip 0 to make delay(x*skip) =0 too
    VoiceActive = true;
}

// load first list. max 7 command active at the same time.
void load_main_commands() {    
    myvr.load(uint8_t(heyakno)); // hey acno
    myvr.load(uint8_t(youknowwhat)); // go
    myvr.load(uint8_t(gotoo)); // right
    myvr.load(uint8_t(letsplay)); // turn
    myvr.load(uint8_t(whoareyou)); // dance
    myvr.load(uint8_t(showsetting)); // left
    myvr.load(uint8_t(iloveyou)); // back

    firstlist = true;
    seclist = false;
    thirdlist = false;
    fourthlist = false;
    
}

// load the second list. max 7 command active at the same time.
void load_chatting_commands() {    
    myvr.load(uint8_t(heyakno));
    myvr.load(uint8_t(ihateyou));
    myvr.load(uint8_t(youarestupid));
    myvr.load(uint8_t(imsorry));
    myvr.load(uint8_t(nicewheels));
    myvr.load(uint8_t(crazy));
    myvr.load(uint8_t(partytime));

    firstlist = false;
    seclist = true;
    thirdlist = false;
    fourthlist = false;

}

void load_moving_commands() {   
    myvr.load(uint8_t(heyakno));
    myvr.load(uint8_t(goright));
    myvr.load(uint8_t(goleft));
    myvr.load(uint8_t(goforward));
    myvr.load(uint8_t(gobackward));
    myvr.load(uint8_t(spining));
    myvr.load(uint8_t(doproblems));

    firstlist = false;
    seclist = false;
    thirdlist = true;
    fourthlist = false;

}

void load_settings_commands() {    
    myvr.load(uint8_t(heyakno));
    myvr.load(uint8_t(expressions));
    myvr.load(uint8_t(battreylevel));
    myvr.load(uint8_t(colortest));
    myvr.load(uint8_t(voicetraining));
    myvr.load(uint8_t(testmotors));
    myvr.load(uint8_t(testbuttons));

    firstlist = false;
    seclist = false;
    thirdlist = false;
    fourthlist = true;

}



void train_voice() { 
  int visibility =1;  
  bool blink_ok = false;
        
// Categorie commands selecting menu 
   while(1){ 
         
    u8g2.setDrawColor(1);  
    CurrentTime1 = millis();
   u8g2.clearBuffer();
   u8g2.setFont(u8g2_font_helvB08_tf); 
  u8g2.drawFrame(0,0,128,64);
  u8g2.drawStr(15, 12, "Select the Categorie");
  u8g2.drawHLine(5, 17, 118);
  u8g2.drawStr(5, 37, categories[categorie_num]);
  u8g2.drawButtonUTF8(110, 59, U8G2_BTN_INV, 0,  2,  2, "OK");    
  u8g2.sendBuffer();
              
    if(comp(buttonvalue[0])){
          categorie_num++;                   
            delay(200);  }
     if(comp(buttonvalue[1])){
            categorie_num--;                   
            delay(200);   }                                                                   
           
    if(comp(buttonvalue[2])&&((CurrentTime1-PrevTime1) > 1100)&&(categorie_num<4)){
         PrevTime1=CurrentTime1;  

// Command selecting menu                    
    while(1)  {                
     CurrentTime1 = millis();
    u8g2.clearBuffer();
  u8g2.drawFrame(0,0,128,64);
  u8g2.setFont(u8g2_font_helvB08_tf); 
  u8g2.drawStr(16, 12, categories[categorie_num] );
  u8g2.drawHLine(5, 16, 118);
  u8g2.drawStr(23, 28, "Select Command");      
  u8g2.drawButtonUTF8(110, 59, U8G2_BTN_INV, 0,  2,  2, "OK" );          
  u8g2.drawStr(5, 45, commands[command_num]);
 u8g2.drawStr(110, 45, numbers[command_num]); 
  u8g2.sendBuffer();
                
        if(comp(buttonvalue[2])&&((CurrentTime1-PrevTime1) > 800)){ 
       PrevTime1=CurrentTime1;
                    
// training instruction menu      
     while(1) {       
     CurrentTime1 = millis();                
    u8g2.clearBuffer();
  u8g2.drawFrame(0,0,128,64);
  u8g2.setFont(u8g2_font_helvB08_tf); 
  u8g2.drawStr(5, 10, "Start speak when the" );
  u8g2.drawStr(5, 21, "light turned red and");
  u8g2.drawStr(5, 33, "stop when it doesn't"); 
       u8g2.setDrawColor(visibility);   
  u8g2.drawButtonUTF8(110, 59, U8G2_BTN_INV, 0,  2,  2, "OK" );
        u8g2.setDrawColor(1);                  
  u8g2.drawHLine(5, 37, 118);
  u8g2.drawStr(5, 48, commands[command_num]);
 u8g2.drawStr(105, 48, numbers[command_num]); 
  u8g2.sendBuffer(); 

// exit
if(comp(buttonvalue[2])&&((CurrentTime1-PrevTime1) > 400)&&blink_ok){  PrevTime1=CurrentTime1;  
              blink_ok=false;
              break;           }  
            
// blinking OK                                       
      if((CurrentTime1-PrevTime1)>700){      
    visibility<1?visibility++:visibility--; 
          PrevTime1=CurrentTime1; 
            blink_ok = true;  }                
        
     }                 
  
  // start listening and train
   train_state = myvr.train(command_num, buf);   
             PrevTime1=CurrentTime1;                      
} 
                                  
 // trained successed message         
        while(train_state==3){
       CurrentTime1 = millis();     
      u8g2.clearBuffer();
  u8g2.drawFrame(0,0,128,64);
  u8g2.setFont(u8g2_font_helvB08_tf); 
  u8g2.drawStr(28, 12, "Training Done!" );
  u8g2.drawStr(5, 32,commands[command_num]); 
  u8g2.drawStr(110, 32,numbers[command_num]);                         
  u8g2.drawButtonUTF8(110, 59, U8G2_BTN_INV, 0,  2,  2, "OK" );
  u8g2.sendBuffer(); 

// exit                    
if(comp(buttonvalue[2])&&((CurrentTime1-PrevTime1) > 800)){ train_state=0;
        PrevTime1=CurrentTime1;   }         
        
  }                  
// end of train success message                
                         
     if(comp(buttonvalue[0])){
           command_num++;                   
            delay(250);   }
     if(comp(buttonvalue[1])){
           command_num--;                   
            delay(250);   }                                 
    
      if((comp(buttonvalue[3])||comp(buttonvalue[4]))&&((CurrentTime1-PrevTime1) > 1000)){ PrevTime1=CurrentTime1;       
        break;        }           
                                    
    if(command_num>uprange[categorie_num]){     
         command_num=downrange[categorie_num];                                 
         }                                         
    if(command_num<downrange[categorie_num]){                    
         command_num=uprange[categorie_num];   }                    
 }//end while
             
                  
            delay(300);
  
     } // endif 
  else if(comp(buttonvalue[2])&&(categorie_num==4)&&((CurrentTime1-PrevTime1) > 1000)){
       
     while(1){
                
          CurrentTime1 = millis();
                
        info();
                
        if((comp(buttonvalue[3])||comp(buttonvalue[4]))&&((CurrentTime1-PrevTime1) > 1000)){
        PrevTime1=CurrentTime1;
        break;     } 
     }
  }
        
       if((comp(buttonvalue[3])||comp(buttonvalue[4]))&&((CurrentTime1-PrevTime1) > 1000)){
        PrevTime1=CurrentTime1;
        myvr.clear();
        load_main_commands();
        break;        } 
        
       
  if(categorie_num>categorie_item-1){
         categorie_num=0;        }
  if(categorie_num<0) { 
       categorie_num=categorie_item-1;   }
 
         
     }    
 }
    

void info(){
    
    u8g2.clearBuffer();
  u8g2.drawFrame(0,0,128,64);
  u8g2.setFont(u8g2_font_helvB08_tf); 
  u8g2.drawStr(42, 12, "Akno Bot" );
  u8g2.drawHLine(5, 14, 118);
  u8g2.drawButtonUTF8(109, 59, U8G2_BTN_INV, 0,  2,  2, "==>" ); 
   
      
    switch(next_page){
        case 0:
  u8g2.drawStr(3, 26, "Software Version 1.1");      
  u8g2.drawStr(3, 38, "By Abdulsalam Abbod");
  u8g2.drawStr(3, 50, "Vist my github page");
  u8g2.sendBuffer();
    break;
        
        case 1: 
 u8g2.drawStr(3, 26,"for checking updates :");      
  u8g2.drawStr(2, 40, "github/AbdulsalamAbbod");
  u8g2.drawStr(3, 53, "/Akno");
  u8g2.sendBuffer();        
            break; 
       }    

 if(comp(buttonvalue[2])){           
    next_page>0?next_page=0:next_page++;
        delay(400);       }
}





