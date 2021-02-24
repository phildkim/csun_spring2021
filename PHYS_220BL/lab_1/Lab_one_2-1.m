clearvars
format long
RHO=1./1.45e6;% Siemens(1/Ωm)
L=[2,4,6,8,10];% Length
V=[1.00,0.98,1.01,1.01,0.99];% Voltage
I=[0.062,0.030,0.021,0.016,0.012];% Current
N=length(L);% Length
R=V./I;% Voltage / Current
figure(1),plot(R,L,'ob');
hold on
fontSize=18;
set(gca,'fontSize',fontSize);
title('Resistance vs. Length');
xlabel('Resistance (R)');
ylabel('Length (L)');
A=L*RHO./R;
D=sqrt(4*A./pi);
A1=mean(A);
D1=mean(D);
SIGMAA=std(A);
SIGMAD=std(D);
T1=['A,\sigma_{A} = ' num2str(A1) ' \pm' num2str(SIGMAA)];
T2=['D,\sigma_{D} = ' num2str(D1) ' \pm' num2str(SIGMAD)];
P=polyfit(R,L,1);
F=P(1)*R+P(2);
H=figure(1),plot(R,F,'-r');
ylim([0,11]);
xlim([0,90]);
text(10,10,T1);
text(10,9.5,T2);
exportgraphics(H,'Lab1_2.pdf');

