% tan(θ) vs. Bᵢ
T=[1.44e-4,8.65e-5,5.22e-5,3.02e-5,2.50e-5,2.15e-5];
B=[-2.90,-1.15,-2.49,1.05,2.13,2.68];
TB=T./B;
n=length(TB);
SLOPE=sum(TB)/n;
ERROR=sqrt(sum(abs(TB-SLOPE).^2)/(n-1));
P=polyfit(B,T,1);
F=P(1)*B+P(2);
[SLOPE,ERROR]% custom: slope +/- error
[P(1),std(TB)]% check: slope +/- error
figure(1);
hold on;
box on;
plot(B,T,'sr',B,F,'-b','Linewidth',1.5);
fontSize=18;
set(gca,'fontSize',fontSize);
title('$tan(\theta_i)$ vs $B_i$', 'Interpreter', 'latex');
xlabel('$B_i$', 'Interpreter', 'latex');
ylabel('$tan(\theta_i)$', 'Interpreter', 'latex');
hold off;
