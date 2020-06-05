%05/22/2020-Final project epidemic Program to model an infectious disease - super simplified.
% Equations : dS/dt = -r S I
%             dR/dt = a I
%             dI/dt = -dS/dt - dR/dt - b I
% time measured in days
%S=susceptibles , R=recovereds, I=infecteds.
%             L=(S+R+I)(0)- (S+I+R)(t)
dt=1 % change in time by one day. Day one, Day two ...
r=1e-7 % the transmission rate
%r=5e-8
a=0.05 % recovery rate 
b=a*0.01% mortality rate
%b=a*0.04
S0=8315200 %susceptible initial/ population
R0=0 % recovered initial 
I0=100 % infected initial
tmax=62 % days between March 1 to May 1
popscale=8315200 % population scale for graphing
t= 0:dt:tmax;
S(1)=S0; % initial values for susceptible - people that CAN get infected
R(1)=R0; % the initial reccovery rate - people who have recovered from being infected
I(1)=I0; % the initial infected rate - people who have been infected
itmax=ceil(tmax/dt)
for it=2:itmax+1
    dSodt(it)=-r*S(it-1)*I(it-1);
    S(it)=S(it-1)+dSodt(it)*dt;
    dRodt(it)=a*I(it-1);
    R(it)=R(it-1)+dRodt(it)*dt;
    dIodt(it)=-dSodt(it)-dRodt(it)-b*I(it-1);
    I(it)=I(it-1)+dIodt(it)*dt;
end 
L=(S0+I0+R0)-(S+I+R); % number of losses throughout the epidemic

dL(1)= 0; % don't know dL(1) just use a convenience
for it=2:itmax+1
    dL(it) = L(it) - L(it - 1); % deaths per timestep or deaths/timestep
end
dLodt = dL/dt; % the total lost of people over time each day

%plot(t,S)
%axis([0 tmax 0 popscale])
%xlabel('time in days')
%ylabel('Number Susceptible')
%title('Epidemic simulation of NYC from near start')
plot(t,I)
axis([0 tmax 0 popscale])
xlabel('time in days')
ylabel('Number Infected')
title('Epidemic simulation of NYC from near start')
%plot(t,R)
%axis([0 tmax 0 popscale])
%xlabel('time in days')
%ylabel('Number Recovered')
%title('Epidemic simulation of NYC from near start')
popscale=100000
bar(t,L)
axis([0 tmax 0 popscale])
xlabel('time in days')
ylabel('Number Lost')
title('Epidemic simulation of NYC from near start')
deathRateScale = 5000;
bar(t,dLodt)
axis([0 tmax 0 deathRateScale])
xlabel('Time in Days')
ylabel('Number of Losses per Day')
    

