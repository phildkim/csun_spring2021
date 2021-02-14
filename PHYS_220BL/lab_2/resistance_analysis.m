function resistance=resistance_analysis(v,i)
    format long;
    r=v./i;
    n=length(r);
    slope=sum(r)/n;
    uncertainty=sqrt(sum(abs(r-slope).^2)/(n-1));
    resistance=[slope,uncertainty];
end