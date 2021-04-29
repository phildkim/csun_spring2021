% Graph 1: subplots, plot V_dischage vs t as scatterplot in semilogarithmic plot, using semilogy.
% For each determine τ=RC from the semilogarithmic fit and plot fit as lineplot.

figure();

x1 = [12.50, 11.36, 10.00, 9.80, 9.62];
y1 = [1.13, 1.29, 1.40, 1.49, 1.61];
p1 = polyfit(x1, log(y1), 1);
tau1 = -1 / p1(1);
v1 = exp(p1(2));
subplot(2, 2, 1);
semilogy(x1, y1, 'o', x1, v1 * exp(-x1 / tau1), '-');
xlim([9.45, 12.65]);
ylim([1.00, 1.70]);
xlabel('$t_{screen}$', 'Interpreter', 'latex');
ylabel('$V_{discharge}$', 'Interpreter', 'latex');
title('100$\Omega$: $V_{discharge}(V)$ vs $t_{screen}(s)$', 'Interpreter', 'latex');

x2 = [7.81, 7.75, 7.64, 7.34, 7.00];
y2 = [1.12, 1.21, 1.29, 1.38, 1.47];
p2 = polyfit(x2, log(y2), 1);
tau2 = -1 / p2(1);
v2 = exp(p2(2));
subplot(2, 2, 2);
semilogy(x2, y2, 'o', x2, v2 * exp(-x2 / tau2), '-');
xlim([6.90, 7.90]);
ylim([1.05, 1.55]);
xlabel('$t_{screen}$', 'Interpreter', 'latex');
ylabel('$V_{discharge}$', 'Interpreter', 'latex');
title('150$\Omega$: $V_{discharge}(V)$ vs $t_{screen}(s)$', 'Interpreter', 'latex');

x3 = [5.32, 5.38, 5.26, 5.16, 5.00];
y3 = [1.13, 1.20, 1.29, 1.35, 1.47];
p3 = polyfit(x3, log(y3), 1);
tau3 = -1 / p3(1);
v3 = exp(p3(2));
subplot(2, 2, 3);
semilogy(x3, y3, 'o', x3, v3 * exp(-x3 / tau3), '-');
xlim([4.95, 5.45]);
ylim([1.10, 1.55]);
xlabel('$t_{screen}$', 'Interpreter', 'latex');
ylabel('$V_{discharge}$', 'Interpreter', 'latex');
title('270$\Omega$: $V_{discharge}(V)$ vs $t_{screen}(s)$', 'Interpreter', 'latex');

x4 = [22.73, 20.63, 20.41, 20.20, 19.83];
y4 = [1.13, 1.23, 1.32, 1.40, 1.49];
p4 = polyfit(x4, log(y4), 1);
tau4 = -1 / p4(1);
v4 = exp(p4(2));
subplot(2, 2, 4);
semilogy(x4, y4, 'o', x4, v4 * exp(-x4 / tau4), '-');
xlim([19.65, 22.90]);
ylim([1.05, 1.55]);
xlabel('$t_{screen}$', 'Interpreter', 'latex');
ylabel('$V_{discharge}$', 'Interpreter', 'latex');
title('47$\Omega$: $V_{discharge}(V)$ vs $t_{screen}(s)$', 'Interpreter', 'latex');





% Graph 2: plot τ vs R as a scatterplot, fit with straight line, draw the fit as lineplot and report the slope.

x1 = [12.50, 11.36, 10.00, 9.80, 9.62];
y1 = [1.13, 1.29, 1.40, 1.49, 1.61];
p1 = polyfit(x1, log(y1), 1);
tau1 = -1 / p1(1);

x2 = [7.81, 7.75, 7.64, 7.34, 7.00];
y2 = [1.12, 1.21, 1.29, 1.38, 1.47];
p2 = polyfit(x2, log(y2), 1);
tau2 = -1 / p2(1);

x3 = [5.32, 5.38, 5.26, 5.16, 5.00];
y3 = [1.13, 1.20, 1.29, 1.35, 1.47];
p3 = polyfit(x3, log(y3), 1);
tau3 = -1 / p3(1);

x4 = [22.73, 20.63, 20.41, 20.20, 19.83];
y4 = [1.13, 1.23, 1.32, 1.40, 1.49];
p4 = polyfit(x4, log(y4), 1);
tau4 = -1 / p4(1);

r = [100, 150, 270, 47];
t = [tau1, tau2, tau3, tau4];
r0 = r ./ t;
p = polyfit(r, t, 1); % x = x data, y = y data, 1 = order of the polynomial i.e a straight line
f = p(1) * r + p(2);
slope = sum(r0) / length(r0);
error = sqrt(sum(abs(r0 - slope).^2) / (length(r0) - 1));
% hold on;
box on;
scatter(r, t, 'or');
plot(r, f, '-b');
xlim([40, 280]);
ylim([0, 12.5]);
xlabel('$R$', 'Interpreter', 'latex');
ylabel('$t_{screen}$', 'Interpreter', 'latex');
title('$t_{screen}$ vs $R$', 'Interpreter', 'latex');
% hold off;



% Vmax = 0.77;
% Vmin = -0.77;

% V_screenDIV = 4.0; % vertical
% t_screenDIV = 2.4; % hortizontal

% V_minV = 0.2 / V_screenDIV; % vertical
% t_screenS = 50 / t_screenDIV; % hortizontal

% V_screenV = Vmax - Vmin;
% V_dischargeV = V_screenV - V_minV;
