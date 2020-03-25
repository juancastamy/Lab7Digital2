/*  /*
 * Seven lab for Digital 2 course  
 * File:   lab7.ino
 * Author: Juan Castillo
 * Student ID: 17074
 *
 * Created on March 24, 2020
 */


/*
  SD card read/write

  This example shows how to read and write data to and from an SD card file
  The circuit:
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

File myFile;
int x = 0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 

  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  Serial.println("");
  Serial.println("Please enter your character");
  Serial.println("");
  Serial.println("METROID");
  Serial.println("");
  Serial.println("LINK");
  Serial.println("");
  Serial.println("WALUIGI");  
  


}

void loop() {
  if(Serial.available()>0){
  x = Serial.read();
  }
  if(x==77){
    // re-open the file for reading:
    myFile = SD.open("METROID.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
  }
  if(x==78){
    // re-open the file for reading:
    myFile = SD.open("LINK.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
  }
  if(x==87){
    // re-open the file for reading:
    myFile = SD.open("WALUIGI.txt");
    if (myFile) {
      Serial.println("Archivo:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
  }
}
