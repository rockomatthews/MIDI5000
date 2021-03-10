

# MIDI5000 Project

## ReadMe Entry 5000 (previously referred to as ReadMe Entry 4) 
The project has alas hit a milestone. MIDI5000 works as expected. I made 4 MIDI buttons and 1 potentiometer control any aspect of a DAW over WiFi with zero latency. The project uses an esp32 PCB board and was coded with the Arduino IDE.

I could easily have easily created 4 times the amount of controls but my need was specific. I only wanted 4 buttons and 1 potetiometer because that's all that I had room for on my guitar. I used the tiniest of boards I could find too because, in a case like this where dealing with very little room (the area under a guitar's pickup guard that is already cramped), less is more. Here is a video of a tiny board controlling Abelton LIVE on a Mac over Wifi. This could fit in my guitar without much effort and is mimics the start of "My Name Is Thunder" by The Bloody Beetroots.

[![controller](https://imgur.com/9ytHnLH)](https://www.youtube.com/watch?v=WkeB3Opa6Q4 "esp-32 buttons with a potentiometer controlling Ableton LIVE via MIDI")

-First the board connects to WiFi shared from my MacBook Pro.
-Once connected (turned on/given battery power) it comes up as a virtual instrument in the Audio MIDI Setup App located in Utilities on a Mac.
-This means my computer is recognizing it as if it were a controller or keyboard plugged in with a MIDI cord.
-The easiest way to make this as customizable as possible was to keep the logic to the lights associated with the buttons. 
-Only under certain circumstances are MIDI messages sent. MIDI's language is incredibly simple and versatile.  

A next step this project could take would be utilizing the MIDI Designer Pro 2 App on an iPhone. This could make the buttons completely customizable without having to edit the code. 

And/Or the Mac App MIDIStroke could be used to take the buttons a step further and control any on my Mac.  MIDIStroke converts MIDI messages (a channel, a value) into a keystroke.  That means the buttons could control anything that uses a hotkey. 

To push past that, Alfred Mac app could assign triggers to any of the above keystrokes to command my Mac to do any workflow imaginable... 


## ReadMe Entry 1
Trying to make customizable buttons for a WiFi MIDI controller. I call it MIDI5000. So far I have successfully utilized a esp-32 pcb board to connect to my Mac's shared internet (my mac is acting as a wireless router) via WiFi.  

The Apple MIDI library then lets me connect to Mac's Audio MIDI Setup App (found within Utilities) where the board gets registered as a MIDI device that can send and receive MIDI messsages like any other MIDI controller that plugs in.
Link to Apple MIDI Library for Arduino: https://github.com/lathoub/Arduino-AppleMIDI-Library

I have made 4 ON/OFF buttons so far work successfully without any interference from each other. I've made them latency-free and found the right sensitivity spots to ensure rapid, light, hard, slo imultaneous pushes work and feel good.

Plan:
This prototype will actually go into one of my guitars. It's called Barsad... the guitar. He was, to Bane, what this guitar is to me. 

So I want two of the buttons to be ON/OFF switches. I have those.

I want the next to be a momentary button. For that, button3's code needs slight altering.

And I want the last button to play a note (F2). Also slight alteration too button4.  

Finally I want a potentiometer at the end that will perform a control change, like the buttons, but the buttons just send a channel, CC value, and Sensitivity or 127 (ON) or 0 (OFF), it will send the channel, CC value, and any number between 0-127 depending on the state the knob is turned.

So whatever software synth it is connected to, when I press the button, if a MIDI track is listening for input/output from channel 13 (MIDI channel buttons are all using in controller), it plays an F2 note until unpressed. On a grand piano VST, that would sound like someone pressing that key on the piano. The sound would naturally fade. In another VST like Massive, it might be a note played by a virtual synthesizer that sustains its noise until released.  Drum VST, play a drum noise, etc etc.  

That might only sound like the ability to play a single note and bend its pitch to you but that combo gives me a ton of ideas.


This dated Sunday, the 19th of Arpil. In the year 2020 | Quarantine status- Yes


## ReadMe Entry 2
Now my buttons are working as planned over Wifi. Video will be added shortly
button 1 - ON/OFF
button 2 - ON/OFF
button 3 - Momentary
button 4 - NoteON/NoteOFF (F2)
potentiometer- (tomorrow)


This dated Tuesday, the 2st of Arpil. In the year 2020 | Quarantine status- Yes

# STAY SAFE

## ReadMe Entry 3 
Milestone hit. Please refer to the top for ##ReadME Entry 4
