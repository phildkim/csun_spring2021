% Graph 1: VR vs. C, VC vs. C, VRC vs. C, Provide the legend so they can be distinguished
% C=[10.00,4.55,3.03,2.13,1.47,1.00];
% C=[0.10,0.22,0.33,0.47,0.68,1.00];


% ordered
C=[0.10e-7,0.22e-7,0.33e-7,0.47e-7,0.68e-7,1.00e-6];
VR=[0.81,1.54,2.02,2.27,2.43,2.51];
VC=[2.54,2.18,1.75,1.41,1.11,0.91];
VRC=[2.67,2.67,2.67,2.67,2.67,2.67];
figure(1);
hold on;
box on;
plot(C,VR,'-b',C,VC,'-r',C,VRC,'-g');
fontSize=18;
set(gca,'fontSize',fontSize);
title('Impedance of a Capacitors: $V_R~vs.~C$, $V_C~vs.~C$, $V_{RC}~vs.~C$','Interpreter','latex');
xlabel('Capacitors ($C\mu F$)','Interpreter','latex');
ylabel('Voltage ($V_R$, $V_C$, $V_{RC}$)','Interpreter','latex');
legend('$V_R$', '$V_C$', '$V_{RC}$','Interpreter','latex');
xlim([0,1.1e-6]);
ylim([0.5,3]);
hold off;




% Graph 2: Xc,exp vs 1/C, fit it with a linear line and report the slope and error in the legend
X=[1454.1,873.0,3140.9,611.2,460.9,364.2];
C=[1/0.22,1/0.33,1/0.10,1/0.47,1/0.68,1/1.00];
S=X./C;
N=length(S);
SLOPE=sum(S)/N;
ERROR=sqrt(sum(abs(S-SLOPE).^2)/(N-1));
P=polyfit(C,X,1);
F=P(1)*C+P(2);
[num2str(SLOPE) ' ' num2str(ERROR)]% Check Slope and Error
[num2str(P(1)) ' ' num2str(std(S))]% Check Slope and Error
figure(1);
hold on;
box on;
plot(C,X,'sr',C,F,'-b');
fontSize=18;
set(gca,'fontSize',fontSize);
title('Impedance of Capacitor: $X_{C,exp}$ vs $\frac{1}{C}$','Interpreter','latex');
xlabel('Capacitors ($\frac{1}{C\mu F}$)','Interpreter','latex');
ylabel('Experimental Reactance ($X_{C,exp}\Omega$)','Interpreter','latex');
xlim([C(6)-0.5,C(3)+1]);
ylim([X(1)-314.09,X(6)+36.42]);
hold off;



X=[1342.2,894.8,2952.8,628.3,434.2,295.3];
C=[1/0.22,1/0.33,1/0.10,1/0.47,1/0.68,1/1.00];
S=X./C;
N=length(S);
SLOPE=sum(S)/N;
ERROR=sqrt(sum(abs(S-SLOPE).^2)/(N-1));