n=[1,2,3,4];

vr1=[2.10,2.35,2.19,1.86];
vr2=[2.67,2.43,2.02,1.86];
vr3=[2.67,2.35,1.94,1.78];

vc1=[4.0251,3.8845,3.9769,4.1415];
vc2=[3.6719,3.8349,4.0659,4.1415];
vc3=[3.6719,3.8845,4.1046,4.1765];

vrc=[4.54,4.54,4.54,4.54];

% Xc vs. N (fit it with a linear line and report the slope and error in the legend. Report the offset and its error)
n=[1,2,3,4];
xc1=[894.47,776.90,846.15,1035.40];
xc2=[644.19,737.48,945.56,1035.40];
xc3=[644.19,776.90,1001.10,1099.10];
xc=[sum(xc1)/length(n),sum(xc2)/length(n),sum(xc3)/length(n)];
slope=sum(xc)/3;
error=sqrt(sum(abs(xc-slope).^2)/(length(n)-1));
p=polyfit(n,xc,1);
f=p(1)*n+p(2);
figure();
hold on;
plot(n,xc,'sr',n,f,'-b');
fontSize=18;
set(gca,'fontSize',fontSize);
title('X_C vs. n', 'Interpreter', 'latex');
xlabel('No. of Paper (n)');
ylabel('');
