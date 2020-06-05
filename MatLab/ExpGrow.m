A0=60000000; % initial population
k=0.02; %growth rate (unit year^ -1)
A(1)=A0;
Amax = 50000000; %limiting population
tmax=200; %simulation time (unit year)
dt=(1/12); % simulation timestep (unit year)

lmax=ceil(tmax/dt);
for l=1:lmax
    A(l + 1)=A(l)* (1+ dt*k*(1 -A(l)/Amax));
end

t=0:dt:tmax
plot(t,A);
axis([0 tmax 1 5*A0]);
xlabel('time in hours');
ylabel('human population');
title('Constrained population growth');
