
/*********
  Modified from the examples of the Arduino LoRa library
  More resources: https://randomnerdtutorials.com
  src: https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/
*********/

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 15
#define rst 0
#define dio0 27
int a = analogRead(14);


void setup() {
  //initialize Serial Monitor
  Serial.begin(9600);
  pinMode(a, INPUT);
  //Serial.println("1");
  while (!Serial); //mengaktifkan jika serial terdeteksi //fungsi looping mengulang sampai benar
  Serial.println("LoRa Sender"); 

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(921E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!"); 
}

void loop() {
  Serial.print(a);
  LoRa.beginPacket();
  LoRa.print(a);
  LoRa.endPacket();
  delay(100);
}
