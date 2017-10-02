#include <SPI.h>
#include "RF24.h"

RF24 rf24(0,1);//CE CNS

const byte addr[]="1Node";
uint8_t pipes=1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
rf24.begin();
rf24.setChannel(83);
rf24.setPALevel(RF24_PA_MIN);
rf24.setDataRate(RF24_1MBPS);
rf24.openReadingPipe(pipes,addr);
rf24.startListening();
Serial.println("nRF24L01 ready");
}

void loop() {
  // put your main code here, to run repeatedly:  
 // Serial.println("no");
  if(rf24.available(&pipes))  
  {
    char msg[32] = "";
    rf24.read(&msg,sizeof(msg));
    Serial.println(msg);
  }
}
