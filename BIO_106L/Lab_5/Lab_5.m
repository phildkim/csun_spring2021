% Scleropodium obtusifolium
L1=[2.36,2.67,2.95,2.16,1.96,2.82,2.64,2.97,2.57,2.67,2.21,2.91,2.08,2.54,2.35];
W1=[1.62,1.65,1.87,1.29,1.29,1.76,1.67,1.9,1.53,1.8,1.47,1.91,1.31,1.62,1.44];
R1=W1./L1;
N1=length(R1);
M1=sum(R1)/N1;
std_dev1=sqrt(sum(abs(R1-M1).^2)/(N1-1));
std_err1=std_dev1./sqrt(N1);

% Scleropodium possible new-sp
L2=[1.82,2.41,2.03,2.16,2.18,1.95,2.61,2.41,2.46,1.86,2.15,2.13,1.89,2.78,2.49];
W2=[1.65,2.21,1.77,2,1.96,1.86,2.25,2.11,2.1,1.75,1.78,1.9,1.59,2.44,2.47];
R2=W2./L2;
N2=length(R2);
M2=sum(R2)/N2;
std_dev2=sqrt(sum(abs(R2-M2).^2)/(N2-1));
std_err2=std_dev2./sqrt(N2);


col(1,:)=[0, 0.4470, 0.7410]; % blue
col(2,:)=[0.4660, 0.6740, 0.1880]; % green
x=categorical({'obtusifolium','new sp'}); % xaxis
x=reordercats(x,{'obtusifolium','new sp'}); % specified order
y=[M1,M2];
m=[std_dev1,std_dev2];
e=[std_err1,std_err2];
h=figure(1);
hold on;
b=bar(x,y,0.3,'FaceColor',col(2,:));
b.FaceColor='flat';
b.CData=col;
errorbar(x,y,-e,e,'linestyle','none','CapSize',20,'LineWidth',2,'Color',[1 0 0]);
fontSize=15;
set(gca,'fontSize',fontSize);
ylabel('Width:Length');
xlabel('Species');
exportgraphics(h,['Lab5.png']);
hold off;
