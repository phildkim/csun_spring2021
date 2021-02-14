N=6;
% Voltage vs. Current for R1
V1=[1.12,2.02,2.99,3.95,5.07,6.09];
I1=[0.056,0.103,0.148,0.198,0.250,0.308];
figure(1),plot(I1,V1,'or');
hold on
fontSize=18;
set(gca,'fontSize',fontSize);
title('Voltage vs. Current for R1')
xlabel('Current (I)')
ylabel('Voltage (V)')
R1=analysis(V1,I1,N,1);
P1=polyfit(I1,V1,1);
F1=P1(1)*V1+P1(2);
H=figure(1),plot(I1,F1,'-r');
xlim([0.05,0.33])
ylim([1,6.5])
text(0.05,5,R1);
