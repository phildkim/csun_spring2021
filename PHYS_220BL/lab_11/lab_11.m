% y vs x^2
y = [2.38, 2.13, 1.78, 1.38, 1.28, 1.18, 1.10, 0.75, 0.45, 0.30];
yb = [2.36, 2.06, 1.46, 1.33, 1.26, 1.16, 1.10, 0.5, 0.4, 0.30];
x = [8.3^2, 8.0^2, 7.3^2, 7.0^2, 6.3^2, 6.0^2, 5.3^2, 5.0^2, 4.3^2, 4.0^2];
s = x/y;
SLOPE = sum(s) / length(yb);
ERROR = sqrt(sum(abs(s - SLOPE).^2) / (length(yb) - 1));
ERRBAR=y-yb;
P = polyfit(x, y, 1);
F = P(1) * x + P(2);
P1 = polyfit(x, yb, 1);
F1 = P1(1) * x + P1(2);
figure(1);
hold on;
box on;
plot(x, y, 'sr', x, F, '-b', x, F1, '-r', 'Linewidth', 1.5);
errorbar(x,y,ERRBAR);
fontSize = 18;
set(gca, 'fontSize', fontSize);
title('$y$ vs $x^2$', 'Interpreter', 'latex');
xlabel('$x^2$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
xlim([12.8 72.8]);
ylim([0.09 2.59]);
hold off;



























% tan(θ) vs. Bᵢ
T = [-2.90, -1.15, -0.25, 0.11, 0.21, 0.27];
B = [14.4e-5, 8.65e-5, 5.22e-5, 3.02e-5, 2.50e-5, 2.15e-5];
TB = T ./ B;
n = length(TB);
SLOPE = sum(TB) / n;
ERROR = sqrt(sum(abs(TB - SLOPE).^2) / (n - 1));
P = polyfit(B, T, 1);
F = P(1) * B + P(2);
[SLOPE, ERROR] % custom: slope +/- error
[P(1), std(TB)] % check: slope +/- error
figure(1);
hold on;
box on;
plot(B, T, 'sr', B, F, '-b', 'Linewidth', 1.5);
fontSize = 18;
set(gca, 'fontSize', fontSize);
title('$tan(\theta_i)$ vs $B_i$', 'Interpreter', 'latex');
xlabel('$B_i$', 'Interpreter', 'latex');
ylabel('$tan(\theta_i)$', 'Interpreter', 'latex');
dim = [0.2 0.5 0.3 0.3];
str = {['Slope = ' num2str(SLOPE) ' \pm ' num2str(ERROR, 4) '\Omega']};
annotation('textbox', dim, 'String', str, 'FitBoxToText', 'on', 'fontSize', 15);
hold off;




errorbar(x, y, err);
xlabel('$x^2$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
title('y vs. $x^2$', 'Interpreter', 'latex');





















err = [-0.03,-0.08,-0.33,-0.03,-0.03,-0.03,0.00,0.25,0.05,0.00];
R = y./z;
n = length(R);
R_slope = sum(R) / n;
R_error = sqrt(sum(abs(R - R_slope).^2) / (n - 1));
p = polyfit(x, y, 1);

