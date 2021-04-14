Vrc=1.70;
Vc=1.74;
f=40029;
f0=1/(2*pi*100*2.2e-7);
H_the=1/sqrt(1+(f0/f)^2)
H_exp = Vc/Vrc;


% High-Pass Filter Graph: Plot Hexp vs. f from part 1 on a double logarithmic plot (replace 'plot' in matlab/GNU octave by 'loglog'). Use symbols, not lines. Now plot in the same plot Htheo as a line plot.
H_EXP = [0.1905, 0.3598, 0.6717, 0.8969, 0.9368, 0.9570, 0.9780, 0.9770];
H_THE = [0.1403, 0.2936, 0.5787, 0.801, 0.9023, 0.9405, 0.9722, 0.9841];
F_OSC = [1025, 2222, 5133, 10010, 15143, 20029, 30024, 40029];
figure(1);
hold on;
box on;
loglog(F_OSC, H_EXP, 's', 'MarkerFaceColor', [0 0.447 0.741]);
plot(F_OSC,H_THE,'--db');
title('High-Pass Filter: $H_{exp}~vs~f$, $H_{the}~vs~f$', 'Interpreter', 'latex');
xlabel('Frequency (Hz)', 'Interpreter', 'latex');
ylabel('Ratio of Voltage ($\left|H_{exp}\right|=\frac{V_R}{V_{RC}})$', 'Interpreter', 'latex');
legend('$H_{exp}$', '$H_{the}$', 'Interpreter', 'latex');
hold off;


% Low-Pass Filter Graph: Do the same thing for the data in part 2.
H_EXP = [0.9588, 0.8586, 0.6856, 0.5619, 0.3441, 0.2857, 0.2218, 0.1687];
H_THE = [0.9879, 0.9559, 0.8156, 0.5857, 0.4311, 0.3397, 0.2343, 0.1778];
F_OSC = [1138, 2222, 5133, 10010, 15143, 20029, 30019, 40029];
figure(1);
hold on;
box on;
loglog(F_OSC, H_EXP, 's', 'MarkerFaceColor', [0 0.447 0.741]);
plot(F_OSC, H_THE, '--db');
title('Low-Pass Filter: $H_{exp}~vs~f$, $H_{the}~vs~f$', 'Interpreter', 'latex');
xlabel('Frequency (Hz)', 'Interpreter', 'latex');
ylabel('Ratio of Voltage ($\left|H_{exp}\right|=\frac{V_C}{V_{RC}})$', 'Interpreter', 'latex');
legend('$H_{exp}$', '$H_{the}$', 'Interpreter', 'latex');
hold off;
