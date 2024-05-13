#include <Arduino.h>

#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2SNoDAC.h"

#include "acomer.h"
#include "guauguau.h"
const int analogInPin = A0;

AudioGeneratorWAV *wav;
AudioFileSourcePROGMEM *file;
AudioOutputI2SNoDAC *out;

int acumulator=0, tempo=0, block=0, tempo_300=0;

int sensorValue = 0;


void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.printf("Microwave system starts\n");

  audioLogger = &Serial;
  
  out = new AudioOutputI2SNoDAC();
  wav = new AudioGeneratorWAV();
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}

// This loop applies to my particular microwave that has the buzzer data as:
// a signal of 2kHz modulated in NRZ by a 20 Hz 
void loop()
{ 
  if (wav->isRunning()) {
    if (!wav->loop()) wav->stop();
    } 
  else{
    digitalWrite(LED_BUILTIN, HIGH);
    delayMicroseconds(300);
    sensorValue = analogRead(analogInPin);
    Serial.print(sensorValue);
    Serial.println('\n');
    tempo += 1;
    
    if(sensorValue >= 180) acumulator += 1;
    // Takes 40 samples windows and checks if there was signal in al least the half of the samples
    if(tempo == 40){
      if(acumulator >= 20) block+= 1;
      tempo_300 += 1;
      tempo = 0;   
      acumulator = 0;
    }

    // after 15 blocks analyze the status of the input data
    if(tempo_300 >= 15){
      if (block  <= 9  && block  >= 4 ) {
        file = new AudioFileSourcePROGMEM( guauguau, sizeof(guauguau) );
        wav->begin(file, out);
        delay(50);
      }
      if (block  >= 11) {
        file = new AudioFileSourcePROGMEM( acomer, sizeof(acomer) );
        wav->begin(file, out);
        delay(50);
      }
      acumulator = 0;
      block = 0;
      tempo_300 = 0;
    }
    }
}
  