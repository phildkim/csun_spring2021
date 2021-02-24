clearvars
format long
RHO=1./1.45e6;% Siemens(1/Ωm)
I=[0.012,0.023,0.036,0.046,0.058,0.06900000000000001];% Current
V=[1.05,2.01,3.06,3.98,4.95,5.98];% Voltage
N=length(I);% Length
R=V./I;% Voltage / Current
figure(1),plot(I,V,'ob');
hold on
fontSize=18;
set(gca,'fontSize',fontSize);
title('Voltage vs. Current');
xlabel('Current (I)');
ylabel('Voltage (V)');
R1=mean(R);
SIGMAR=std(R);
T1=['R,\sigma_{R} = ' num2str(R1) ' \pm' num2str(SIGMAR)];
P=polyfit(I,V,1);
F=P(1)*I+P(2);
H=figure(1),plot(I,F,'-r');
ylim([0.5,6.5]);
xlim([0,0.08]);
text(0.01,5,T1);
exportgraphics(H,'Lab1_1.pdf');