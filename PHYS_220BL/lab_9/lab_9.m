% Graph 1: 4 subplots for the 4 datasets for the 4 different resistors, plot V_dischage vs t as a scatterplot in a semilogarithmic plot, using semilogy in matlab/GNU octave.

R=100;
C=2.2e-7;
T=R*C;
t_s1 = [130, 250, 0, -130, -250];
V_dischage1=V0 * e^(−t_s1 / T)


V_dischage1 = [0.8,1.0,0.4,0.2,0.0];
K = t_s1.^2;
pow = -0.4;
Y = K.^pow;
semilogy(t_s1, V_dischage1);
subplot(3, 1, 1);
plot(K, Y, '.');

t_s2 = [130, 250, 0, -130, -250];
V_dischage2 = [0.68,0.8,0.88,0.52,0.32];
semilogy(t_s2, V_dischage2);
subplot(3, 1, 2);
plot(K, Y, '.');

t_s3 = [120, 250, -130, -200, -250];
V_dischage3 = [0.8, 0.96, 0.04, 0.2, 0.12];
semilogy(t_s3, V_dischage3);
subplot(3, 1, 3);
plot(K, Y, '.');

t_s4 = [120, 250, -130, -200, -250];
V_dischage4 = [0.8,1.0,1.08,0.4,0.2];
semilogy(t_s4, V_dischage4);
subplot(3, 1, 4);
plot(K, Y, '.');


% Graph 2: plot τ vs R as a scatterplot, fit this with a straight line, draw the fit as a lineplot in the same graph and report the slope.

τ=[];
R=[];

