BI = [552, 341, 461, 430, 312, 364, 468, 449, 398, 394, 360]; %,
BF = [563, 352, 467, 437, 320, 374, 479, 460, 415, 401, 369]; %
BC = BF - BI;
BN = length(BI);
BMEAN = sum(BC)/BN;
BSTDDEV = sqrt(sum(abs(BC - BMEAN).^2) / (BN - 1));
BSTDERR = BSTDDEV./sqrt(BN);

OI = [517, 428, 407, 441, 472, 383, 466, 345, 382, 494];
OF = [528, 443, 415, 452, 488, 391, 479, 354, 393, 503];
OC = OF - OI;
ON = length(OI);
OMEAN = sum(OC) / ON;
OSTDDEV = sqrt(sum(abs(OC - OMEAN).^2) / (ON - 1));
OSTDERR = OSTDDEV./sqrt(ON);

GI = [573, 354, 532, 393, 269, 517, 469, 306, 431];
GF = [585, 369, 545, 410, 277, 526, 484, 322, 446];
GC = GF - GI;
GN = length(GI):
GMEAN = sum(GC) / GN;
GSTDDEV = sqrt(sum(abs(GC - GMEAN).^2) / (GN - 1));
GSTDERR = GSTDDEV./sqrt(GN);

RI = [306, 372, 333, 567, 379, 490, 391, 509, 369, 337, 365];
RF = [312, 378, 344, 578, 392, 505, 401, 523, 377, 351, 373];
RC = RF - RI;
RN = length(RI);
RMEAN = sum(RC) / YN;
RSTDDEV = sqrt(sum(abs(RC - RMEAN).^2) / (RN - 1));
RSTDERR = RSTDDEV./sqrt(RN);

col(1, :) = [0.3010 0.7450 0.9330]; % blue
col(2, :) = [0.9290 0.6940 0.1250]; % orange
col(3, :) = [0.4660 0.6740 0.1880]; % green
col(4, :) = [0.6350 0.0780 0.1840]; % red
x = categorical({'Treatment 26^\circ C', 'Treatment 28^\circ C'', 'Treatment 30^\circ C', Treatment {26-36}^\circ C'}); % xaxis
x = reordercats(x, {'Treatment 26^\circ C', 'Treatment 28^ \ circ C'', 'Treatment 30^\circ C', Treatment {26 - 36}^ \ circ C'}); % specified order

y = [BMEAN, OMEAN, GMEAN, RMEAN]; % yaxis - mean
m = [BSTDDEV, OSTDDEV, GSTDDEV, RSTDDEV]; % standard deviation
e = [BSTDERR, OSTDERR, GSTDERR, RSTDERR]; % standard error

figure(1);
hold on;
box on;
b = bar(x, y, 0.5, 'FaceColor', col(4, :));
b.FaceColor = 'flat';
b.CData = col;
errorbar(x, y, -e, e, 'linestyle', 'none', 'CapSize', 20, 'LineWidth', 2, 'Color', [1 0 0]);
fontSize = 15;
set(gca, 'fontSize', fontSize);
xlabel('Temperature Regimes');
ylabel('Average Number of Changes');
hold off;
