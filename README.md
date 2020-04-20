# arduino
Arduino projects in Arduino IDE with python

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
