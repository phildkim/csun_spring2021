function h=plot_resistance(i,v,r,str,fig)
    format short g;
    n=length(i);
    p=polyfit(i,v,1);
    f=p(1)*i+p(2);
    hold off;
    h=figure(fig);
    plot(i,v,'sr',i,f,'-b','Linewidth',1.5);
    fontSize=18;
    set(gca,'fontSize',fontSize);
    title(['Voltage vs. Current for ' str]);
    xlabel('Current (I)');
    ylabel('Voltage (V)');
    x=i(1)+.05;
    y=v(n)-1;
    x0=i(1)-.02;
    x1=i(n)+.02;
    if fig == 3
       str = 'R_S';
       x=i(1)+.02;
    elseif fig == 4
       str = 'R_P';
       x0=i(1)-.04;
       x1=i(n)+.07;
    end
    xlim([x0,x1]);
    ylim([v(1)-.5,v(n)+.5]);
    txt=[str ' = ' num2str(round(r(1),2)) ' \pm' num2str(round(r(2),2)) '\Omega'];
    text(x,y,txt,'FontSize',14);
    exportgraphics(h,['Lab_3_figure_' num2str(fig) '.pdf']);
end

