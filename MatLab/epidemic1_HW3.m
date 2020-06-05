% Chinedu Ejiogu HW3 - 05/27/2020 Program to model an infectious disease - super simplified.
% Equations : dS/dt = -r S I
%             dR/dt = a I
%             dI/dt = -dS/dt - dR/dt - b I
% time measured in days
%S=susceptibles , R=recovereds, I=infecteds.
%             L=(S+R+I)(0)- (S+I+R)(t)
dt=1
r=3e-8 % change from hw3 
%r=5e-8
a=0.05
b=a/100; % change from hw3
%b=a*0.04
S0=7e6; % change initial value(susceptible/population)from hw3
R0=6e6; % change initial value(recovery rate)from hw3
I0=1e6; % change initial value(infected rate) from hw3
tmax=90;
popscale=8000000 %population scale for graphing
t= 0:dt:tmax ;
S(1)=S0;
R(1)=R0;
I(1)=I0;
itmax=ceil(tmax/dt)
for it=2:itmax+1
    dSodt(it)=-r*S(it-1)*I(it-1);
    S(it)=S(it-1)+dSodt(it)*dt;
    dRodt(it)=a*I(it-1);
    R(it)=R(it-1)+dRodt(it)*dt;
    dIodt(it)=-dSodt(it)-dRodt(it)-b*I(it-1);
    I(it)=I(it-1)+dIodt(it)*dt;
end 
L=(S0+I0+R0)-(S+I+R);
%popscale = 7500000;
bar(t,S)
axis([0 tmax 0 popscale])
xlabel('time in days')
ylabel('Number Susceptible')
title('Epidemic simulation of NYC from near start')
%popscale = 5000000;
bar(t,I)
axis([0 tmax 0 popscale])
xlabel('time in days')
ylabel('Number Infected')
title('Epidemic simulation of NYC from near start')
%popscale = 20000000;
bar(t,R)
axis([0 tmax 0 popscale])
xlabel('time in days')
ylabel('Number Recovered')
title('Epidemic simulation of NYC from near start')
popscale=100000;
bar(t,L)
axis([0 tmax 0 popscale])
xlabel('time in days')
ylabel('Number Lost')
title('Epidemic simulation of NYC from near start')
    
    

