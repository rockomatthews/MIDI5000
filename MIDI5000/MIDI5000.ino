#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

#include "AppleMidi.h"
  
char ssid[] = "rob69"; //  your network SSID (name)
char pass[] = "testtest";    // your network password (use for WPA, or use as key for WEP)

// constants won't change
const int button1_Pin = 4;
const int LED1_PIN = 16;
const int button2_Pin = 18;
const int LED2_PIN = 19;
const int button3_Pin = 22;
const int LED3_PIN = 23;
const int button4_Pin = 32;
const int LED4_PIN = 33;

const int DEBOUNCE_DELAY = 50;   // the debounce time; increase if the output flickers
  
// variables will change:

// -----------------------------------------------------------------------------
// button 1 states
// -----------------------------------------------------------------------------
int lastSteady1State = LOW;       // the previous steady state from the input pin
int lastFlickerable1State = LOW;  // the previous flickerable state from the input pin
int led1State = LOW;     // the current state of LED
int lastButton1State;    // the previous state of button
int currentButton1State; // the current state of button

// -----------------------------------------------------------------------------
// button 2 states
// -----------------------------------------------------------------------------
int lastSteady2State = LOW;       // the previous steady state from the input pin
int lastFlickerable2State = LOW;  // the previous flickerable state from the input pin
int led2State = LOW;     // the current state of LED
int lastButton2State;    // the previous state of button
int currentButton2State; // the current state of button

// -----------------------------------------------------------------------------
// button 3 states
// -----------------------------------------------------------------------------
int lastSteady3State = LOW;       // the previous steady state from the input pin
int lastFlickerable3State = LOW;  // the previous flickerable state from the input pin
int led3State = LOW;     // the current state of LED
int lastButton3State;    // the previous state of button
int currentButton3State; // the current state of button

// -----------------------------------------------------------------------------
// button 4 states
// -----------------------------------------------------------------------------
int lastSteady4State = LOW;       // the previous steady state from the input pin
int lastFlickerable4State = LOW;  // the previous flickerable state from the input pin
int led4State = LOW;     // the current state of LED
int lastButton4State;    // the previous state of button
int currentButton4State; // the current state of button

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long t0 = millis();
bool isConnected = false;

APPLEMIDI_CREATE_INSTANCE(WiFiUDP, AppleMIDI); // see definition in AppleMidi_Defs.h

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  pinMode(button1_Pin, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(LED1_PIN, OUTPUT);          // set arduino pin to output mode
  pinMode(button2_Pin, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(LED2_PIN, OUTPUT);          // set arduino pin to output mode
  pinMode(button3_Pin, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(LED3_PIN, OUTPUT);          // set arduino pin to output mode
  pinMode(button4_Pin, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(LED4_PIN, OUTPUT);          // set arduino pin to output mode
  
  currentButton1State = digitalRead(button1_Pin);
  currentButton2State = digitalRead(button2_Pin);
  currentButton3State = digitalRead(button3_Pin);
  currentButton4State = digitalRead(button4_Pin);
    
  Serial.print(F("Getting IP address..."));
  
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println(F(""));
  Serial.println(F("WiFi connected"));


  Serial.println();
  Serial.print(F("IP address is "));
  Serial.println(WiFi.localIP());

  Serial.println(F("OK, now make sure you an rtpMIDI session that is Enabled"));
  Serial.print(F("Add device named Arduino with Host/Port "));
  Serial.print(WiFi.localIP());
  Serial.println(F(":5004"));
  Serial.println(F("Then press the Connect button"));
  Serial.println(F("Then open a MIDI listener (eg MIDI-OX) and monitor incoming notes"));

  // Create a session and wait for a remote host to connect to us
  AppleMIDI.begin("test");

  AppleMIDI.OnConnected(OnAppleMidiConnected);
  AppleMIDI.OnDisconnected(OnAppleMidiDisconnected);

}

void loop() {
   
   AppleMIDI.read();

// -----------------------------------------------------------------------------
// Button 1
// -----------------------------------------------------------------------------
   
   if (currentButton1State != lastFlickerable1State) {
     // reset the debouncing timer
     lastDebounceTime = millis();
     // save the the last flickerable state
     lastFlickerable1State = currentButton1State;
   }
    
  lastButton1State    = currentButton1State;      // save the last state
  currentButton1State = digitalRead(button1_Pin); // read new state
  
  
  if(lastButton1State == HIGH && currentButton1State == LOW) {
    Serial.println("The button is active");

    // toggle state of LED
    led1State = !led1State;

    // control LED arccoding to the toggled state
    digitalWrite(LED1_PIN, led1State);
    
    if (led1State == HIGH) {
      AppleMIDI.sendControlChange(85, 127, 13);
      } else {
        AppleMIDI.sendControlChange(85, 0, 13);
        Serial.println("The button is not active");
    }
    delay(100);
  } 

// -----------------------------------------------------------------------------
// Button 2
// -----------------------------------------------------------------------------

    if (currentButton2State != lastFlickerable2State) {
      // reset the debouncing timer
      lastDebounceTime = millis();
      // save the the last flickerable state
      lastFlickerable2State = currentButton2State;
    }
  
   lastButton2State    = currentButton2State;      // save the last state
   currentButton2State = digitalRead(button2_Pin); // read new state
  
  
   if(lastButton2State == HIGH && currentButton2State == LOW) {
    Serial.println("The button is active");

      // toggle state of LED
      led2State = !led2State;

    // control LED arccoding to the toggled state
    digitalWrite(LED2_PIN, led2State);
    
    if (led2State == HIGH) {
      AppleMIDI.sendControlChange(86, 127, 13);
      } else {
        AppleMIDI.sendControlChange(86, 0, 13);
        Serial.println("The button is not active");
    }
    delay(100);
  }


//// -----------------------------------------------------------------------------
//// Button 3
//// -----------------------------------------------------------------------------
   
   if (currentButton3State != lastFlickerable3State) {
     // reset the debouncing timer
     lastDebounceTime = millis();
     // save the the last flickerable state
     lastFlickerable3State = currentButton3State;
   }
    
  lastButton3State    = currentButton3State;      // save the last state
  currentButton3State = digitalRead(button3_Pin); // read new state
  
  
  if(lastButton3State == HIGH && currentButton3State == LOW) {
    Serial.println("The button is active");

    // toggle state of LED
    led3State = !led3State;

    // control LED arccoding to the toggled state
    digitalWrite(LED3_PIN, led3State);
    
    if (led3State == HIGH) {
      AppleMIDI.sendControlChange(87, 127, 13);
      } else {
        AppleMIDI.sendControlChange(87, 0, 13);
        Serial.println("The button is not active");
    }
    delay(100);
  }

// -----------------------------------------------------------------------------
// Button 4
// -----------------------------------------------------------------------------
   
   if (currentButton4State != lastFlickerable4State) {
     // reset the debouncing timer
     lastDebounceTime = millis();
     // save the the last flickerable state
     lastFlickerable4State = currentButton4State;
   }
    
  lastButton4State    = currentButton4State;      // save the last state
  currentButton4State = digitalRead(button4_Pin); // read new state
  
  
  if(lastButton4State == HIGH && currentButton4State == LOW) {
    Serial.println("The button is active");

    // toggle state of LED
    led4State = !led4State;

    // control LED arccoding to the toggled state
    digitalWrite(LED4_PIN, led4State);
    
    if (led4State == HIGH) {
      AppleMIDI.sendControlChange(88, 127, 13);
      } else {
        AppleMIDI.sendControlChange(88, 0, 13);
        Serial.println("The button is not active");
    }
    delay(100);
  }

  
}

// ====================================================================================
// Event handlers for incoming MIDI messages
// ====================================================================================

// -----------------------------------------------------------------------------
// rtpMIDI session. Device connected
// -----------------------------------------------------------------------------
void OnAppleMidiConnected(uint32_t ssrc, char* name) {
  isConnected  = true;
  Serial.print(F("Connected to session "));
  Serial.println(name);
}

// -----------------------------------------------------------------------------
// rtpMIDI session. Device disconnected
// -----------------------------------------------------------------------------
void OnAppleMidiDisconnected(uint32_t ssrc) {
  isConnected  = false;
  Serial.println(F("Disconnected"));
}
