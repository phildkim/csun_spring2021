a=IDH([7,7,2,4,11,13,4,10,4,4,6,7,7,1,11,4,21,19,9,7,8,6,15,7,12,11,23,12,13]);
b=IDH([13,9,4,4,14,14,10,7,7,7,5,6,3,5,15,9,15,14,13,14,11,10,12,11,15,14,30,7,20]);
c=IDH([3,4,4,2,10,8,8,8,6,4,5,5,5,8,9,8,14,15,10,20,17,14,18,5,10,9,13,8,12]);
col(1,:)=[0 1 1]; % red
col(2,:)=[1 1 0]; % yellow
col(3,:)=[0 1 0]; % green
x=categorical({'A: No disturbance','B: Intermediate disturbance','C: High disturbance'}); % xaxis
x=reordercats(x,{'A: No disturbance','B: Intermediate disturbance','C: High disturbance'}); % specified order
y=[a(1),b(1),c(1)]; % yaxis - mean
m=[a(2),b(2),c(2)]; % standard deviation
e=[a(3),b(3),c(3)]; % standard error
h=figure(1);
hold on;
b=bar(x,y,0.5,'FaceColor',col(3,:));
b.FaceColor='flat';
b.CData=col;
errorbar(x,y,-e,e,'linestyle','none','CapSize',20,'LineWidth',2,'Color',[1 0 0]);
fontSize=15;
set(gca,'fontSize',fontSize);
xlabel('Disturbance Level');
ylabel('Average number of Morphospecies');
exportgraphics(h,['IDH.png']);
hold off;
