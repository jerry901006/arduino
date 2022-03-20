

#include "Game_Audio.h"
#include "SoundData.h"

Game_Audio_Class GameAudio(25,0); 

Game_Audio_Wav_Class pmWav(SoundData_wav);                            
                                      

void setup() {
  Serial.begin(115200); 
  Serial.println("Begin...");
}

void loop() {   
 Serial.print("Sample Rate (Hz):");
 Serial.println(pmWav.getSampleRate());
 Serial.print("Duration (secs):");
 Serial.println(pmWav.getDuration());
 
    GameAudio.PlayWav(&pmWav, false, 1.0);
 
 // wait until done
 while(GameAudio.IsPlaying()){  
 }
 
}
