% Parallel
R_ep=[0.34,0.90,0.18,0.12,0.08];
R_th=[0.33,0.91,0.18,0.09,0.0099];
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
title('Series Resistors: $\frac{V_1}{V_{12}}$ vs. $\frac{R_1}{R_1+R_2}$','Interpreter','latex');
xlabel('$\frac{V_1}{V_{12}}$','Interpreter','latex');
ylabel('$\frac{R_1}{R_1+R_2}$','Interpreter','latex');
box on;
hold off;
exportgraphics(h,'lab5_series.jpeg');




R_ep=[1.08,0.086,1.38,1.42,1.97];
R_th=[1.05,0.09524,1.4,1.6,1.96];
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
title('Parallel Resistors: $R_{23,exp}$ vs. $R_{23,theory}$','Interpreter','latex');
xlabel('$R_{23,exp}$','Interpreter','latex');
ylabel('$R_{23,theory}$','Interpreter','latex');
box on;
hold off;
exportgraphics(h,'lab5_parallel.jpeg');