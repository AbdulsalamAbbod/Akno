/*
Voice Commands contains all commands signature and it's location at the voice recognition module memory
2022/9/19.  7:46pm
*/

#ifndef voice_commands_h
#define voice_commands_h

#include "Arduino.h"


// here is the voice command signature and the location of it at the voice recognition module memory


// Hey Akno 
#define heyakno 0// calling akno
#define youknowwhat 1             
#define gotoo 2        
#define letsplay 3    
#define whoareyou 4     
#define showsetting 5   
#define iloveyou 6  

// You know what??
//      heyakno 0  
#define ihateyou 7    
#define youarestupid 8  
#define imsorry 9      
#define nicewheels 10  
#define crazy 11
#define partytime 12   

// goto command
//      heyakno 0
#define goright 13   
#define goleft 14    
#define goforward 15  
#define gobackward 16  
#define spining  17    
#define doproblems  18

// Show Setting 
//      heyakno 0
#define expressions 19   
#define battreylevel 20   
#define colortest 21       
#define voicetraining  22
#define testmotors   23
#define testbuttons 24







#endif
