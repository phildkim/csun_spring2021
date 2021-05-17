x=[8.3^2,8.0^2,7.3^2,7.0^2,6.3^2,6.0^2,5.3^2,5.0^2,4.3^2,4.0^2];
y=[2.38,2.13,1.78,1.38,1.28,1.18,1.10,0.75,0.45,0.30];
err = [-0.03,-0.08,-0.33,-0.03,-0.03,-0.03,0.00,0.25,0.05,0.00];
R = y./z;
n = length(R);
R_slope = sum(R) / n;
R_error = sqrt(sum(abs(R - R_slope).^2) / (n - 1));
p = polyfit(x, y, 1);
errorbar(x, y, err);
xlabel('$x^2$', 'Interpreter', 'latex');
ylabel('$y$', 'Interpreter', 'latex');
title('y vs. $x^2$', 'Interpreter', 'latex');
