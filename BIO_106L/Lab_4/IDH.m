function species=IDH(x)
  format long;
  n=length(x);
  mean=sum(x)/n;
  std_dev=sqrt(sum(abs(x-mean).^2)/(n-1));
  std_err=std_dev./sqrt(n);
  species=[mean,std_dev,std_err];
end
