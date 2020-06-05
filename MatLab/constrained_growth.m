A0=60000000; % initial population
k=0.02; %growth rate (unit year^ -1)
A(1)=A0;
Amax = 50000000; %limiting population
tmax=200; %simulation time (unit year)
dt=(1/12); % simulation timestep (unit year)
ttotal=3600;

lmax=ceil(tmax/dt);
for l=1:lmax
    A(l + 1)=A(l)* (1+ dt*k*(1 -A(l)/Amax));
end

t=0:dt:tmax
plot(t,A)
axis([0 tmax 0 5*A0]);
xlabel('time in years');
ylabel('human population');
title('Constrained population growth');

t_th=0:dt:ttotal;
a_th=exp(-C*t_th)*a(1);
plot(t_th,(a-a_th)./a_th);
axis([0. ttotal  -2*dtrat 2*dtrat])
%axis([0. ttotal  -0.002*dtrat 0.002*dtrat]) % for centered scheme
xlabel('time in seconds')
ylabel('(sim. ex. number - theo. ex. number)/theo. ex. number')
title('decay simulation proportional error')