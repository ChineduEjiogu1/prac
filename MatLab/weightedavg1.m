%200304-10CS345 weightedavg: Based on simpleavg.m calculate a weighted average
%With your data for Ri and K_H in a file JAN1941sample,
clear
load JAN1941sample
data= JAN1941sample
lon=data(:,1);
lat=data(:,2);
depthi=data(:,3);
kh=data(:,5);
ri=data(:,4);

mask=(ri~=-1.e30);

dimen=size(kh)
n=dimen(1)
thick
wt=wt'
wt=wt.*mask
rikhwtav1
