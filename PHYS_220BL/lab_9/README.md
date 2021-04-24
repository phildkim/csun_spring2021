#

The height of a single box is specified as "V/DIV" for the voltage and corresponds to the yellow setting, in the figure "0.2V", which should be read as "0.2V/DIV".

The width of a single box is specified as "s/DIV" for time and in the image corresponds to the green "50us", and corresponds to "50us/DIV".

Therefore, if you want to measure time, you measure the number of horizontal boxes, or rather, DIVs (this can be a fraction too), and multiply by the timescale "50us/DIV" (or whatever it is at this moment) to get the time.

To get a voltage, you use the vertical number of DIVs and multiply by your settings for V/DIV.

The square wave looks on the oscilloscope like the left figure.

The amplitude of this particular signal is V₀ ≈ 1.2V, and that quantity is reported as Vₚₚ by the oscilloscope, while the RMS value is 0.6V.

The frequency f is 4kHz which means every cycle takes 1/f=0.25ms and half of that is spent at Vₘᵢₙ and the other half at Vₘₐₓ.

Since it spends half at one voltage and the other half at the other, this is a so-called duty cycle of 0.5, which the oscilloscope reports as Duty: 49.5% in the figure.

When recording voltages in this experiment, we will be recording voltage differences between the point on the screen and Vₘᵢₙ:

V(t)=Vₛᵣₑₑₙ₍ₜ₎ − Vₘᵢₙ

Therefore, V₀ = Vₘₐₓ − Vₘᵢₙ
