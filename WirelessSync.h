///*
// * Aurora: https://github.com/pixelmatix/aurora
// *
// * RF24 wireless sync
// * Copyright (c) 2015 Konstantin Gredeskoul
// *
// * Permission is hereby granted, free of charge, to any person obtaining a copy of
// * this software and associated documentation files (the "Software"), to deal in
// * the Software without restriction, including without limitation the rights to
// * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// * the Software, and to permit persons to whom the Software is furnished to do so,
// * subject to the following conditions:
// *
// * The above copyright notice and this permission notice shall be included in all
// * copies or substantial portions of the Software.
// *
// * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// */
//
//#ifndef WirelessSync_H
//#define WirelessSync_H
//
//#include "Aurora.h"
//#include "Externs.h"
//#include <RF24.h>
//
//#define WIRELESS_RECEIVER 0
//#define WIRELESS_SENDER 1
//#define WIRELESS_SLEEPER 2
//
//uint64_t addresses[] = { 0x3245, 0x3267 };
//struct dataStruct {
//    unsigned long _micros;
//    float value;
//} myData;
//
//
//class WirelessSync {
//private:
//
//    int role;
//    RF24& radio;
//    unsigned long lastReadMs = 0;
//    unsigned long readEveryMs = 2000;
//
//public:
//    WirelessSync(RF24 &theRadio, int theRole) :
//            radio(theRadio) {
//        role = theRole;
//    }
//
//    void header() {
//        Serial.println();
//        Serial.print(F("Aurora/RF24, Role: "));
//        Serial.println((char *) addresses[role]);
//    }
//
//    void begin() {
//        header();
//
//        radio.begin();
//
//        // Set the PA Level low to prevent power supply related issues since this is a
//        // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
//        radio.setPALevel(RF24_PA_LOW);
//
//        // Open a writing and reading pipe on each radio, with opposite addresses
//        if (role == WIRELESS_SENDER) {
//            radio.openWritingPipe(addresses[1]);
//            radio.openReadingPipe(1, addresses[0]);
//            radio.stopListening();
//            Serial.println("Configured radio as a sender.");
//        } else {
//            radio.openWritingPipe(addresses[0]);
//            radio.openReadingPipe(1, addresses[1]);
//            radio.startListening();
//            Serial.println(
//                    "Configured radio as a receiver, started listening.");
//        }
//        radio.printDetails();
//
//        myData.value = 1.22;
//    }
//
//    void sync() {
//        if (millis() - lastReadMs > readEveryMs) {
//            lastReadMs = millis();
//            if (radio.available()) {
//                Serial.println("Radio is available");
//                radio.printDetails();
//            }
////
////        if (role == WIRELESS_SENDER) {
////            myData._micros = micros();
////            Serial.print(F("Sending ["));
////            Serial.print(myData._micros);
////            Serial.println(F("] microseconds..."));
////
////            if (!radio.write(&myData, sizeof(myData))) {
////                Serial.println(F("Error sending request..."));
////            }
////        }
////
////            if (role == WIRELESS_RECEIVER) {
////                if (radio.available()) {
////                    // Variable for the received timestamp
////                    while (radio.available()) {     // While there is data ready
////                        radio.read(&myData, sizeof(myData));  // Get the payload
////                    }
////                    radio.stopListening();
////                    Serial.print(F("Received packet: ["));
////                    Serial.print(myData._micros);
////                    Serial.print(":");
////                    Serial.print(myData.value);
////                    Serial.print(F("], "));
////                    myData.value += 0.01;                   // Increment the float value
////                    radio.write(&myData, sizeof(myData));    // Send the final one back.
////                    radio.startListening(); // Now, resume listening so we catch the next packets.
////                    Serial.print(F("sent response: ["));
////                    Serial.print(myData._micros);
////                    Serial.print(":");
////                    Serial.print(myData.value);
////                    Serial.println(F("], "));
////                } else {
////                    Serial.println("No data available");
////                }
////            }
//        }
//    }
//};
//
//#endif
