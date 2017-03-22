#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

const int switchPin = 8;
int switchState = 0;
int prevSwitchState = 0;

char *test_audio = "testtoo.wav";
void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

Serial.println("SD i=si");
tmrpcm.setVolume(6);
tmrpcm.play(test_audio);

pinMode (switchPin,INPUT);
}


void loop(){  

switchState = digitalRead (switchPin);

if (switchState != prevSwitchState)
    { 
      if (switchState == HIGH){
//  Serial.print("currState: ");
//Serial.println(switchState);
        tmrpcm.play(test_audio);
        Serial.println("PLAYING SOUND");
        delay(3000);
        tmrpcm.play(test_audio);
        Serial.println("PLAYING SOUND");
        delay(3000);
        tmrpcm.play(test_audio);
        Serial.println("PLAYING SOUND");
        delay(3000);
      }
      prevSwitchState = 0;
  }
  
//prevSwitchState = switchState;

  }
    


