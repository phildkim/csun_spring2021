VR=[0.89 1.94 1.94 2.27 2.43 2.51];
VC=[2.5173 2.1824 1.8345 1.4057 1.1063 0.9104];
VRC=[2.67 2.92 2.67 2.67 2.67 2.67];
C=[.0000001 .0000022 .0000033 .0000047 .0000068 .000001];

figure
hold on
plot(C,VR,'blue',C,VC,'red',C,VRC,'green');
hold off
title('Impedance of a Capacitor: $V_R, V_C, V_{RC}$ vs. C','Interpreter','latex');
xlabel('Capacitor (C)');
ylabel('Voltage ($V_R$, $V_C$, $V_{RC}$)','Interpreter','latex');
legend('$V_R$', '$V_C$', '$V_{RC}$','Interpreter','latex');



R_ep=[1148.6,965.5,2929.4,611.2,461.0,364.2];
R_th=[4.5455,3.0303,10,2.1277,1.4706,1.0000];
R_pp=R_ep./R_th;
n=length(R_pp);
R_slope=sum(R_pp)/n;
R_error=sqrt(sum(abs(R_pp-R_slope).^2)/(n-1));
p=polyfit(R_th,R_ep,1);
f=p(1)*R_th+p(2);
[R_slope,R_error]% custom: slope +/- error
[p(1),std(R_pp)]% check: slope +/- error
h=figure(1);
hold on;
plot(R_th,R_ep,'sr',R_th,f,'-b','Linewidth',1.5);
fontSize=18;
set(gca,'fontSize',fontSize);
title('Impedance of a Capacitor: $X_{C,exp}$ vs. $\frac{1}{C}$','Interpreter','latex');
xlabel('1/Capacitor ($\frac{1}{C}$)','Interpreter','latex');
ylabel('($X_{C,exp}$)','Interpreter','latex');
xlim([0.5,11]);
ylim([0.5,3000]);
box on;
hold off;
exportgraphics(h,'lab6_graph2.jpeg');