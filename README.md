# Wetris: A Real-Time Embedded Game with Soggy Electromechanical Feedback
More detailed, step-by-step assembly manual file coming soon.
  ## Overview
  Wetris is like normal tetris, except it sprays you with water if you lose before reaching a target score! This repo contains all the information you will need to build a clone for yourself using an arduino mega, and a few other common electrical components. Except the door lock actuator from a 2016 grand caravan. That's not very common. :p 
  
  Feel free to create an issue or reach out if you are interested in more info on how we did it!

  ## Me getting sprayed in the face
  ![Image](https://github.com/user-attachments/assets/c33d2e9d-159a-4c0e-9947-f0816f9a8fd7)

  ## Core Archetectural Principles of Software
  The entire wetris system is orgainised into four modules: The user interface (containing buttons and the LCD), the music module, the water gun module, and the speed module. Each module has a C++ library attached to it. `main.cpp` orchestrates interactions between the modules. Each library is designed to be non-blocking to ensure that no module makes the others stall.

  ## How to assemble (will be moved to assembly manual later)
  * 3D print using the STL files linked in the report
  * Epoxy the parts together, epoxy the door lock actuator on the side such that the arm blocks the hole when extended (wait for drying before the next step; optionally drimmel off the residue that leaks between the seams of the parts after it forms large, hard pools; DO NOT SCRAPE OR IT WILL DRY MESSY) I used solid fill for the load bearing parts and 30% gyroid for the non load bearing. 50% gyroid should be fine for load bearing if the budget is tight; that was the original plan.
  * Insert the springloaded plunger into the back compartment, such that it is held back by the door lock actuator and will push the syringe in the front compartment when released
  * Glue breadboards to the top as shown in the photos to get ready for wiring
  * Wire according to the diagrams in the report (the two active pins on the door lock actuator are on the left when the water gun points towards you; please be careful with the barrel jack splitter; this thing is MIT lisenced so you can't sue me)
  * Upload the code to the arduino after setting the target safety score macro in main to whatever you want, bring to party, and torment your friends.
  
```
(Pro tip: Send 'X' over the UART port to prematurely activate the water gun and make your friend hate you forever)
```

  ## How to play
  * Fill the syringe with water and place it in the front compartment with the nozzle inside the apeture.
  * Connect the 12V source first, then, when you are ready to begin playing, connect the 5V source
  * Adjust speed with the potenteometer (optionally adjust this to max while someone else is playing to make them panic)
  * Use the buttons to flip and move pieces (the right side of the playing area is where the score box begins)
  * Tremble in mortification

  ## Bill of Materials
| Component | Source | Cost |
|---|---|---|
| 3D printed casing | UNR Libraries | $263.52 |
| Arduino Mega 2560 | Amazon | $54.02 |
| Multimeter* | Amazon | $34.63 |
| Crimping tool* | Amazon | $34.63 |
| Hosyond 4.0" SPI TFT LCD (ST7796S) | Amazon | $22.72 |
| Wire stripper* | ACE Hardware | $20.56 |
| Door lock actuator (2016 Dodge Grand Caravan) | Amazon | $17.05 |
| Weasch Forward/Reverse Relay Module (12V 10A) | Amazon | $14.42 |
| Syringes | Amazon | $14.06 |
| 12V power adapter | Amazon | $14.06 |
| Extension cord | Amazon | $12.98 |
| Caulk gun* | ACE Hardware | $10.82 |
| Pin connector for actuator | Amazon | $10.27 |
| Electrical tape* | ACE Hardware | $9.30 |
| Wire (16 AWG) | ACE Hardware | $8.66 |
| Inline fuse holder + 3A automotive fuses | ACE Hardware | $12.53 |
| Piezo buzzers (x3) | Amazon | $6.49 |
| Sprinkler head | ACE Hardware | $5.40 |
| Barrel jack splitter | Amazon | $4.30 |
| Misc. (jumper wires, buttons, resistors, breadboard, optocouplers, USB cable, 9V battery) | On hand | $0.00 |
| Epoxy | On hand | $0.00 |
| **Total** | | **$570.43** |

*One-time tool purchase — would not need to be repurchased for future builds. A repeat build would cost approximately $110 less.

  ## Galvanic Isolation
  This project contains a 5V system and a 12V system that are galvanicly isolated. Extreme causion must be exercised to keep them seperate or you may fry your arduino or LCD (as I almost did quite a few times! I ran 12V through the arduino and it made the LCD glow from power leakage; how it didn't blow up I have no idea).

  ## DISCLAIMER
  Working with electricity is enherently dangerous and the dual voltage system and water involved in wetris make it even more so. Do not attempt this project unless you are a competant expert, and unless you are fully comfortable with the fact that by using any information in this repo, you forfeit all right to sue me because of error, omission, or ANYTHING as described in the MIT lisence. Use at your own risk.

  The hardware assembly instructions in this repository are provided for informational purposes only. The author makes no guarantees regarding their accuracy, safety, or fitness for any purpose. You assume all risk and liability for any physical build undertaken based on this information.

  ## License

  MIT License
  
  Copyright (c) 2025 Gabriel Jordaan
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
