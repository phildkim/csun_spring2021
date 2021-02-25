% Parallel
R_ep=[0.67,0.36,0.77,3.36,6.62,8.20];
R_th=[0.67,0.34,0.77,3.36,6.65,8.24];
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
title('Parallel Networks: Experiment vs. Theoretical');
xlabel('R_{P} (Th)');
ylabel('R_{P} (Exp)');
x0=R_th(1);% x-axix: initial
x1=R_th(n);% x-axis: length
y0=R_ep(1);% y-axix: initial
y1=R_ep(n);% y-axis: length
xlim([x0-0.6,x1+0.6]);
ylim([y0-0.6,y1+0.6]);
dim=[0.2 0.5 0.3 0.3];
str={['R_{P} = ' num2str(R_slope) ' \pm ' num2str(round(R_error,4)) '\Omega']};
annotation('textbox',dim,'String',str,'FitBoxToText','on','fontSize',15);
box on;
hold off;
exportgraphics(h,'lab4_parallel.jpeg');

% Series
R_ep=[3.01,1.52,4.31,14.98,29.80,57.40];
R_th=[2.99,1.51,4.29,15.04,29.91,57.37];
R_ss=R_ep./R_th;
n=length(R_ss);
R_slope=sum(R_ss)/n;
R_error=sqrt(sum(abs(R_ss-R_slope).^2)/(n-1));
p=polyfit(R_th,R_ep,1);
f=p(1)*R_th+p(2);
[R_slope,R_error]% custom: slope +/- error
[p(1),std(R_ss)]% check: slope +/- error
h=figure(1);
hold on;
plot(R_th,R_ep,'sr',R_th,f,'-b','Linewidth',1.5);
fontSize=18;
set(gca,'fontSize',fontSize);
title('Series Networks: Experiment vs. Theoretical');
xlabel('R_{S} (Th)');
ylabel('R_{S} (Exp)');
x0=R_th(1);% x-axix: initial
x1=R_th(n);% x-axis: length
y0=R_ep(1);% y-axix: initial
y1=R_ep(n);% y-axis: length
xlim([x0-2.8,x1+4]);
ylim([y0-2.8,y1+4]);
dim=[0.2 0.5 0.3 0.3];
str={['R_{S} = ' num2str(R_slope) ' \pm ' num2str(round(R_error,4)) '\Omega']};
annotation('textbox',dim,'String',str,'FitBoxToText','on','fontSize',15);
box on;
hold off;
exportgraphics(h,'lab4_series.jpeg');
