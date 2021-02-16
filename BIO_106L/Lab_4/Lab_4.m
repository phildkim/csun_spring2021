A=[7,7,2,4,11,13,4,10,4,4,6,7,7,1,11,4,21,19,9,7,8,6,15,7,12,11,23,12,13];
B=[13,9,4,4,14,14,10,7,7,7,5,6,3,5,15,9,15,14,13,14,11,10,12,11,15,14,30,7,20];
C=[3,4,4,2,10,8,8,8,6,4,5,5,5,8,9,8,14,15,10,20,17,14,18,5,10,9,13,8,12];

nA=length(A);
slopeA=sum(A)/nA;
stdA=sqrt(sum(abs(A-slopeA).^2)/(nA-1));
errA=stdA./sqrt(nA);

nB=length(B);
slopeB=sum(B)/nB;
stdB=sqrt(sum(abs(B-slopeB).^2)/(nB-1));
errB=stdB./sqrt(nB);

nC=length(C);
slopeC=sum(C)/nC;
stdC=sqrt(sum(abs(C-slopeC).^2)/(nC-1));
errC=stdC./sqrt(nC);

mean=[slopeA,slopeB,slopeC];
stddev=[errA,errB,errC];
error=[errA,errB,errC];

x=1:3;
bar(x,mean);
xlabel('Disturbance Level');
ylabel('Average number of Morphospecies');
hold on;
eb=errorbar(x,mean,-error,error);
eb.Color = [0 0 0];
eb.LineStyle = 'none';


% Include text box at the end (Example below)
// Above is a plot showing the average number of morphospecies shown in each disturbance level. A is low disturbance, B is intermediate and C is high disturbance. Because the error bars overlap in A and B they are not significantly different, where B and C disturbances do not overlap, meaning that they are significantly different.