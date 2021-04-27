M = [-4.23, 3.5, 2.82, 3.73, 2.98, 0.168, 1.24, -0.16, 2.14, 0.18, 1.06, -1.37, 0.28, 2.84, 1.18, -0.038, 2.18];
N_M = length(M);
MEAN_M = sum(M) / N_M;
STD_M = sqrt(sum(abs(M-MEAN_M).^2)/(N_M-1));
SE_M = STD_M./sqrt(N_M);
CI_M = 2 * SE_M;

F = [-2.25, -1.5, 1.78, 2.97, 3.46, 3.82, -1.14, -1.12, 0.56, -0.92, 3.2, 0.2, -0.38, 2.12, 2.46, 3.25, 2.18];
N_F = length(F);
MEAN_F = sum(F) / N_F;
STD_F = sqrt(sum(abs(F-MEAN_F).^2)/(N_F-1));
SE_F = STD_F./sqrt(N_F);
CI_F = 2 * SE_F;

Na = length(M);
Nb = length(F);
MEANa = sum(M) / Na;
MEANb = sum(F) / Nb;
STDDEVa = sqrt(sum(abs(M - MEANa).^2) / (Na - 1));
STDDEVb = sqrt(sum(abs(F - MEANb).^2) / (Nb - 1));
STDERRa = 2 * (STDDEVa ./ sqrt(Na));
STDERRb = 2 * (STDDEVb ./ sqrt(Nb));

col(1, :) = [0.3010 0.7450 0.9330]; % blue
col(2, :) = [0.4660 0.6740 0.1880]; % green
x = categorical({'Male', 'Female'}); % xaxis
x = reordercats(x, {'Male', 'Female'}); % specified order

y = [MEANa, MEANb]; % yaxis - mean
m = [STDDEVa, STDDEVb]; % standard deviation
e = [STDERRa, STDERRb]; % standard error

figure(1);
hold on;
box on;
b = bar(x, y, 0.5, 'FaceColor', col(2, :));
b.FaceColor = 'flat';
b.CData = col;
errorbar(x, y, -e, e, 'linestyle', 'none', 'CapSize', 20, 'LineWidth', 4, 'Color', [0 0 0]);
fontSize = 24;
set(gca, 'fontSize', fontSize);
xlabel('Sex of Focal Fish');
ylabel('Sex Preference Average');
hold off;
