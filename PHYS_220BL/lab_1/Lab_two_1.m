N=6;
% Voltage vs. Current for R1
V1=[1.12,2.02,2.99,3.95,5.07,6.09];
I1=[0.056,0.103,0.148,0.198,0.250,0.308];
R1=analysis(V1,I1,N,1);
P1=polyfit(I1,V1,1);
F1=P1(1)*V1+P1(2);
figure(1)
subplot(4,1,1)
plot(I1,V1,'or',I1,F1,'-b');
title('Voltage vs. Current for R1')
xlabel('Current (I)')
ylabel('Voltage (V)')
xlim([0.05,0.33])
ylim([1,6.5])

% Voltage vs. CUrrent for R2
V2=[1.06,1.89,3.12,3.97,4.88,5.90];
I2=[0.043,0.079,0.132,0.165,0.200,0.249];
R2=analysis(V2,I2,N,2);
P2=polyfit(I2,V2,1);
F2=P2(1)*V2+P2(2);
subplot(4,1,2)
plot(I2,V2,'or',I2,F2,'-b');
title('Voltage vs. Current for R2')
xlabel('Current (I)')
ylabel('Voltage (V)')
xlim([0.04,0.27])
ylim([1,6.3])

% Voltage vs. Current for R1 and R2 in series R_s=R1+R2
V3=[0.91,2.09,3.08,3.98,5.01,5.97];
I3=[0.021,0.048,0.071,0.091,0.114,0.133];
R3=analysis(V3,I3,N,3);
P3=polyfit(I3,V3,1);
F3=P3(1)*V3+P3(2);
subplot(4,1,3)
plot(I3,V3,'or',I3,F3,'-b');
title('Voltage vs. Current for R1 and R2 in series')
xlabel('Current (I)')
ylabel('Voltage (V)')
xlim([0.02,0.17])
ylim([1,6.5])

% Voltage vs Current for R1 and R2 in parallel R_p=R1*R2./(R1+R2)
V4=[0.93,2.12,3.10,4.10,5.11,5.99];
I4=[0.0841,0.1930,0.2880,0.3800,0.4740,0.5540];
R4=analysis(V4,I4,N,1);
P4=polyfit(I4,V4,1);
F4=P4(1)*V4+P4(2);
subplot(4,1,4)
plot(I4,V4,'or',I4,F4,'-b');
title('Voltage vs. Current for R1 and R2 in parallel')
xlabel('Current (I)')
ylabel('Voltage (V)')
xlim([0.08,0.7])
ylim([1,6.5])