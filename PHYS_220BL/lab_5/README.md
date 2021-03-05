#

- [X] **First step**
  - [X] Plug one of the 9V barrel connectors of the power supply into the oscilloscope.
  - [X] Turn on the oscilloscope.
  - [X] Press the V/DIV button until the yellow reading above it has a rectangle around it.
  - [X] Now it is selected. Use the dial "ADJ" to change that yellow reading to 1V.
  - [X] Now the sensitivity of the oscilloscope is 1V/DIV vertically, which means that one box on the grid translates to 1V.
  - [X] Now, press the SEC/DEV button until the green reading above is selected.
  - [X] Use the dial "ADJ" until it is set to 0.2 ms. The horizontal scale is now 0.2 ms / box.
  - [X] Now press "Trigger" until it is selected and adjust until it reads "AUTO".
  - [X] Finally press the OK button until the display in the top left reads "Running" (If it reads "Hold" it is not updating the screen, which can sometimes be useful).

***

- [X] **Second step**
  - [X] Insert the other 9V power supply into the function generator.
  - [X] Press the middle yellow button until the display reads "OFF".
  - [X] Now use the top yellow button to go through settings.
  - [X] First, make sure that "High speed" says "OFF".
  - [X] If not, press the middle yellow button to change it.
  - [X] Press Up until you see "Freq Step".
  - [X] This is the frequency step that will be used to increment or decrement the frequency of the generator.
  - [X] Use the left or right yellow button to change it to "100 Hz".
  - [X] Now go up until the display reads "SINE".
  - [X] Now use the left and/or right yellow buttons to change the frequency to 1000 Hz.
  - [X] Press the middle yellow button to turn the generator on.

***

- [X] **Third step**
  - [X] Take 4 jumper wires, the breadboard, the BNC alligator wires, and the 1k and 2k resistors out of your kit box (If you don't have that exact value, use the closest one to it and make sure to record it).
  - [X] Insert the resistors into the breadboard as in the figure below (left, click on the figure to zoom in).
  - [X] Make sure the two wires in between R1 and R2 are in the same row on the breadboard.
  - [X] Put the 1k resistor below, and the 2k resistor above.
  - [X] Connect the BNC -alligator to the generator and clip two jumper wires in both alligator clips, and insert the other end of the jumper wires in the breadboard.
  - [X] Make sure that they are in the same row as the resistor ends.
  - [X] The generator is now driving an AC current (I12) through the series connection of R1 and R2.

***

![.](http://www.csun.edu/~hpostma/2021-1-220BL/lab05/images/lab5_setup.jpg)

***

- [ ] **Step 4**
  - [X] Now take the other BNC-alligator wire and connect it to the oscilloscope.
  - [X] Clip the other two jumper wires in the alligator and insert them in the same row as the function generator (middle figure).
  - [X] Make sure the black alligator clips are connected to the same row.
  - [X] Now change the amplitude on the generator such that "VRMS" on the oscilloscope reads approximately 2.0 V.
  - [X] You are now measuring the voltage across both resistors in series, aka V12. Record this in the table below.

***

- [X] **Step 5**
  - [X] Now move the top jumper wire of the oscilloscope to the row in the breadboard between R1 and R2, and record the VRMS value.
  - [X] You are now recording the voltage across the bottom resistor only (R1), aka V1.
  - [X] Calculate the ratio R_1/(R_1+R_2) and V_1/V_12 and enter them in the table.

***

_**Table 1 : series resistors**_

  R₁ | R₂ | V₁ | V/DIV for V₁ | V₁₂ | R₁/(R₁+R₂) | V₁/V₂
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
 1k | 2k | 0.68V | 1V | 2.02V | 0.33 | 0.34V |
 1k | 100 | 0 | 0 | 0 | 0 | 0 |
 1k | 4.7k | 0 | 0 | 0 | 0 | 0 |

***
0.68/2.02=0.34 6634

- [ ] **Step 6**
  - [ ] Now change the top resistor to 100Ω and the other ones listed.
  - [ ] Make sure to adjust the sensitivity of the oscilloscope such the sine wave is not too small on the screen (at least 1 box tall) and record the sensitivities used in the table under "V/DIV".

***

- [ ] **Step 7**
  - [ ] Now add another resistor (R₃) in parallel with R₂.
  - [ ] For this, choose R₃=2.2kΩ.
  - [ ] Now R₂₃ is a parallel configuration of two resistors, R₂ and R₃.
  - [ ] Record the voltage across R₁, i.e. V₁, and then the voltage across all resistors V₁₂₃.
  - [ ] Calculate the current through R₁, I₁=V₁/R₁.
  - [ ] This current is the same as that runs through the parallel resistor R₂₃, i.e. I₂₃=I₁.
  - [ ] Then calculate the voltage across the parallel configuration through V₂₃=V₁₂₃−V₁.
  - [ ] Then, calculate the experimentally determined resistance R₂₃, expt=V₂₃/I₂₃ and the expected theoretical resistance R₂₃, theory=1/(1/R₂+1/R₃).
  - [ ] Only continue if your values are within 10% of each other.

***

- [ ] **Step 8**
  - [ ] Now replace R3 with the values of resistors as tabulated below, repeat the measurements and calculate the extracted parameters.

***

_**Table 2 : parallel resistors**_

  R₁ | R₂ | R₃ | V₁ | V/DIV for V₁ | I₁=I₂₃ | V₁₂₃ | V₂₃ | R₂₃,ₑₓ | R₂₃,ₜₕ
  |:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
  1k | 2k | 2.2k | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  1k | 2k | 100 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  1k | 2k | 4.7k | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  1k | 2k | 10k | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  1k | 2k | 100k | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

***

**Graph 1:**

- Plot V₁/V₁₂ vs. R₁/(R₁+R₂) and fit it with a linear line and report the slope and error in the legend.

***

**Graph 2:**

- Plot R₂₃,ₑₓ vs. R₂₃,ₜₕ and fit it with a linear line and report the slope and error in the legend.

***

**SUBMIT in a single document:**

1. Two pictures with the complete setups for experiments of table 1 and 2.
2. Your data sheet, consisting of the two tables with your data.
3. Graph 1
4. Graph 2
5. Discuss the results from graphs 1 and 2. What did you expect to see, and did you see it? If not, why not. If so, how well (quantitatively) did it fit your expectation?