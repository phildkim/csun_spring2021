A=[17.8,-2.30,-6.2,-3,-10,3.5,-2.5,-10.7,-12,-11];
B=[7.4,10.9,6,-1.2,27.63,31.3,14.2,3.6,1.8,18.6];
Na=length(A);
Nb=length(B);
MEANa=sum(A)/Na;
MEANb=sum(B)/Nb;
STDDEVa=sqrt(sum(abs(A-MEANa).^2)/(Na-1));
STDDEVb=sqrt(sum(abs(B-MEANb).^2)/(Nb-1));
STDERRa=2*(STDDEVa./sqrt(Na));
STDERRb=2*(STDDEVb./sqrt(Nb));

col(1, :) = [0.3010 0.7450 0.9330]; % blue
col(2, :) = [0.4660 0.6740 0.1880]; % green
x = categorical({'Ethanol', 'Caffeine'}); % xaxis
x = reordercats(x, {'Ethanol', 'Caffeine'}); % specified order

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
xlabel('Drug Types');
ylabel('Drug Effect Means');
hold off;
