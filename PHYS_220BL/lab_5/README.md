#
<!-- R₁ R₂ R₃ R₂₃ V₁ V₂ I₁ I₁₂ I₂₃ V₁₂ V₁₂₃ V₂₃ R₂₃,ₑₓₚ R₂₃,ₜₕₑ -->

## Step 1

- [X] Plug one of the 9V barrel connectors of the power supply into the oscilloscope.
- [X] Turn on the oscilloscope.
- [X] Press the V/DIV button until the yellow reading above it has a rectangle around it.
- [X] Now it is selected. Use the dial "ADJ" to change that yellow reading to 1V. Now the sensitivity of the oscilloscope is 1V/DIV vertically, which means that one box on the grid translates to 1V.
- [X] Now, press the SEC/DEV button until the green reading above is selected.
- [X] Use the dial "ADJ" until it is set to 0.2 ms. The horizontal scale is now 0.2 ms / box.
- [X] Now press "Trigger" until it is selected and adjust until it reads "AUTO".
- [X] Finally press the OK button until the display in the top left reads "Running" (If it reads "Hold" it is not updating the screen, which can sometimes be useful).

## Step 2

- [X] Insert the other 9V power supply into the function generator.
- [X] Press the middle yellow button until the display reads "OFF".
- [X] Now use the top yellow button to go through settings.
- [X] First, make sure that "High speed" says "OFF". If not, press the middle yellow button to change it.
- [X] Press Up until you see "Freq Step". This is the frequency step that will be used to increment or decrement the frequency of the generator.
- [X] Use the left or right yellow button to change it to "100 Hz".
- [X] Now go up until the display reads "SINE".
- [X] Now use the left and/or right yellow buttons to change the frequency to 1000 Hz.
- [X] Press the middle yellow button to turn the generator on.

## Step 3

- [X] Take 4 jumper wires, the breadboard, the BNC alligator wires, and the 1k and 2k resistors out of your kit box (If you don't have that exact value, use the closest one to it and make sure to record it).
- [X] Insert the resistors into the breadboard as in the figure below (left, click on the figure to zoom in).
- [X] Make sure the two wires in between R₁ and R₂ are in the same row on the breadboard.
- [X] Put the 1k resistor below, and the 2k resistor above.
- [X] Connect the BNC-alligator to the generator and clip two jumper wires in both alligator clips, and insert the other end of the jumper wires in the breadboard.
- [X] Make sure that they are in the same row as the resistor ends.
- [X] The generator is now driving an AC current (I₁₂) through the series connection of R₁ and R₂.

## Step 4

- [X] Now take the other BNC-alligator wire and connect it to the oscilloscope.
- [X] Clip the other two jumper wires in the alligator and insert them in the same row as the function generator (middle figure).
- [X] Make sure the black alligator clips are connected to the same row.
- [X] Now change the amplitude on the generator such that "VRMS" on the oscilloscope reads approximately 2.0 V.
- [X] You are now measuring the voltage across both resistors in series, aka V₁₂. Record this in the table below.

## Step 5

- [X] Now move the top jumper wire of the oscilloscope to the row in the breadboard between R₁ and R₂, and record the VRMS value.
- [X] You are now recording the voltage across the bottom resistor only (R₁), aka V₁.
- [X] Calculate the ratio R₁/(R₁+R₂2) and V₁/V₁₂ and enter them in the table.
- [X] Checkpoint: Do not proceed until these numbers are within 10% of each other. Subsequent measurements can deviate a little.
- [X] Record the vertical sensitivity of the oscilloscope in the table under "V/DIV".

## Step 6

- [X] Now change the top resistor to 100Ω and the other ones listed.
- [X] Make sure to adjust the sensitivity of the oscilloscope such the sine wave is not too small on the screen (at least 1 box tall) and record the sensitivities used in the table under "V/DIV".

## Step 7

- [ ] Now add another resistor (R₃) in parallel with R₂. For this, choose R₃=2.2kΩ.
- [ ] Now R₂₃ is a parallel configuration of two resistors, R₂ and R₃.
- [ ] Record the voltage across R₁, i.e. V₁, and then the voltage across all resistors V₁₂₃.
- [ ] Calculate the current through R₁, I₁=V₁/R₁. This current is the same as that runs through the parallel resistor R₂₃, i.e. I₂₃=I₁.
- [ ] Then calculate the voltage across the parallel configuration through V₂₃=V₁₂₃-V₁.
- [ ] Then, calculate the experimentally determined resistance R₂₃,ₑₓₚ=V₂₃/I₂₃ and the expected theoretical resistance R₂₃,ₜₕₑ=1/(1/R₂+1/R₃).
- [ ] Only continue if your values are within 10% of each other.

## Step 8

- [ ] Now replace R₃ with the values of resistors as tabulated below, repeat the measurements and calculate the extracted parameters.

## Step 9

- [ ] Graph 1: Plot V₁/V₁₂ vs. R₁/(R₁+R₂) and fit it with a linear line and report the slope and error in the legend.
- [ ] Graph 2: Plot R₂₃,ₑₓₚ vs. R₂₃,ₜₕₑ and fit it with a linear line and report the slope and error in the legend.

## Step 10

- [ ] Submit in a single document

  1. Two pictures with the complete setups for experiments of table 1 and 2.
  2. Your data sheet, consisting of the two tables with your data.
  3. Graph 1
  4. Graph 2
  5. Discuss the results from graphs 1 and 2. What did you expect to see, and did you see it? If not, why not. If so, how well (quantitatively) did it fit your expectation?
R₁ R₂ R₃ R₂₃ V₁ V₂ I₁ I₁₂ I₂₃ V₁₂ V₁₂₃ V₂₃ R₂₃,ₑₓₚ R₂₃,ₜₕₑ
