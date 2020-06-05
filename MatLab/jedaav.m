%190304-10
clear
d
di
jeda
%
load JAN1941sample
data= JAN1941sample
lon=data(:,1);
lat=data(:,2);
depthi=data(:,3);
kh=data(:,5);
ri=data(:,4);
mask=(ri~=-1.e30);
%
wt=thick.*mask
%Initialize sums
sumwt=0.;
sumwtri=0.;
sumwtkh=0.;
for k=1:n
    sumwt=sumwt+wt(k);
    sumwtri=sumwtri+wt(k)*ri(k);
    sumwtkh=sumwtkh+wt(k)*kh(k);
end
riwtav=sumwtri/sumwt
khwtav=sumwtkh/sumwt
