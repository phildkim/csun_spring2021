% plot Zₗ² vs f², linear fit and from the offset and slope, determine R_int and L. Provide a legend for the data and fit

Z = [1.4045^2, 1.6854^2, 2.3121^2, 2.3392^2, 2.3669^2, 2.6786^2, 2.7108^2, 3.0303^2, 3.0488^2];

F=[1000^2, 22000^2,32000^2,39000^2,45000^2,50000^2,55000^2,60000^2,65000^2];

R=Z./F;
n=length(R);
R_slope=sum(R)/n;
R_error=sqrt(sum(abs(R-R_slope).^2)/(n-1));
p=polyfit(F,Z,1);
f=p(1)*F+p(2);
figure();
hold on;
box on;
plot(F,Z,'sr',F,f,'-b','Linewidth',1.5);
fontSize=18;
set(gca,'fontSize',fontSize);
title('$Z_{L,eff}^2$ vs $f^2$', 'Interpreter', 'latex');
xlabel('Hertz ($f^2$)', 'Interpreter', 'latex');
ylabel('Impedance of Inductor ($Z_{L,eff}^2$)', 'Interpreter', 'latex');
xlim([1.34^2, 3.8^2]);
ylim([999^2, 65010^2]);
hold off;






R_ep = [1.34^2, 1.31^2, 1.32^2, 1.32^2, 2^2, 2.01^2, 1.98^2, 1.99^2, 1.99^2];
R_th = [1000^2, 22000^2, 32000^2, 39000^2, 45000^2, 50000^2, 55000^2, 60000^2, 65000^2];
R_pp = R_ep./R_th;
n = length(R_pp);
R_slope = sum(R_pp) / n;
R_error = sqrt(sum(abs(R_pp - R_slope).^2) / (n - 1));
p = polyfit(R_th, R_ep, 1);
f = p(1) * R_th + p(2);
[R_slope, R_error] % custom: slope +/- error
[p(1), std(R_pp)] % check: slope +/- error
h = figure(1);
hold on;
box on;
plot(R_th, R_ep, 'sr', R_th, f, '-b', 'Linewidth', 1.5);
fontSize = 18;
set(gca, 'fontSize', fontSize);
title('$Z_{L,eff}^2$ vs $f^2$', 'Interpreter', 'latex');
xlabel('Hertz ($f^2$)', 'Interpreter', 'latex');
ylabel('Impedance of Inductor ($Z_{L,eff}^2$)', 'Interpreter', 'latex');
x0 = R_th(1); % x-axix: initial
x1 = R_th(n); % x-axis: length
y0 = R_ep(1); % y-axix: initial
y1 = R_ep(n); % y-axis: length
xlim([x0 - 100, x1 + 100]);
ylim([y0 - 10, y1 + 10]);
hold off;








R = 100;
Hz = 65000;
V_RL = 3.28;
V_L = 0.10;

R_int = R ./ ((V_RL ./ V_L) - 1);
I_R = V_RL / R;
Z_L = V_L / I_R;
X_L = sqrt(abs(Z_L^2 - R_int^2));
L = X_L ./ (2 * pi * Hz);

V1 = 2.7e-6;
V2 = L;
RATIO = (abs(V1 - V2) ./ ((V1 + V2) ./ 2)) * 100;
