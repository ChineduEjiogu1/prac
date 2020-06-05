deg=pi/180.
a=1.
b=1.
for itheta=0:360
    jtheta=itheta+1;
    theta(jtheta)=itheta*deg;
end
x=cos(theta)*a;
y=sin(theta)*b;
plot(x,y)
