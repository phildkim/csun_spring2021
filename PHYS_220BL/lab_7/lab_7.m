N=[1,2,3,4];
VRC=[4.54,4.54,4.54,4.54];
VR=[3.97,3.81,3.65,3.43];
VC=[2.20,2.46,2.70,2.98];
figure(1);
hold on;
box on;
plot(N,VRC,'-sg',N,VR,'-sb',N,VC,'-sr');
fontSize=18;
set(gca,'fontSize',fontSize);
title('$V_{RC}~vs.~N$, $V_R~vs.~N$, $V_C~vs.~N$', 'Interpreter', 'latex');
xlabel('No. of paper (N)');
ylabel('Voltage (V)');
legend('$V_{RC}$', '$V_R$', '$V_C$', 'Interpreter', 'latex');
xlim([0.8, 4.2]);
ylim([2, 4.70]);
hold off;

% VR
% (3.97 + 4.05 + 3.89) / 3
% 3.97
% (3.89 + 3.89 + 3.65) / 3
% 3.81
% (3.65 + 3.73 + 3.56) / 3
% 3.65
% (3.48 + 3.40 + 3.40) / 3
% 3.43

% VC
% (2.2024 + 2.0516 + 2.3408) / 3
% 2.20
% (2.3408 + 2.3408 + 2.6998) / 3
% 2.46
% (2.6998 + 2.5882 + 2.8174) / 3
% 2.70
% (2.9157 + 3.0086 + 3.0086) / 3
% 2.98

% XC
% (260.74 + 238.09 + 282.83) / 3
% 260.55
% (282.83 + 282.83 + 346.65) / 3
% 304.10
% (346.65 + 326.13 + 371.97) / 3
% 348.25
% (393.78 + 415.89 + 415.89) / 3
% 408.52

N=[1,2,3,4];
XC=[260.55,304.10,348.25,408.52];
SLOPE=sum(XC)/length(N);
ERROR=sqrt(sum(abs(XC-SLOPE).^2)/(length(N)-1));
P=polyfit(N,XC,1);
F=P(1)*N+P(2);
figure(1);
hold on;
box on;
plot(N,XC,'sr',N,F,'-b');
fontSize=18;
set(gca,'fontSize',fontSize);
title('$X_C$ vs $N$','Interpreter','latex');
xlabel('No. of paper ($N$)','Interpreter','latex');
ylabel('Reactance ($X_C$)','Interpreter','latex');
xlim([0.8, 4.2]);
ylim([250, 420]);
hold off;
