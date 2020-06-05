%190315[Ides of March]-16AH Reworking of old exponential decay program.
%	a(l) is the amount of neutrons at timestep l-1 .
clear
a(1)=1.e6 %a(1) is A_0 , the amount at time 0
t(1)=0
%dt=1
%dt=10
dt=60
%dt=600
%dt=1200
%dt=1800
C=1./1200.
dtrat=dt*C	%timestep divided by the timescale 1/decayrate
ttotal=3600.
nl=ttotal/dt
%Simulated
for l=1:nl
    t(l+1)=l*dt;
    %forward %a(l+1)=(1-C*dt)*a(l);
    % backward a(l + 1) = a(l)/(1 + C * dt);
    a(l + 1) = a(l) * 0.5 * ( (1 - C *dt) + (1/(1+C * dt)) ); % for centered scheme
end
%%Simulated Plot
plot(t,a);
axis([0. ttotal  -2*a(1) 2*a(1)])
xlabel('time in seconds')
ylabel('expectation number of neutrons')
title('simulated neutron decay')
%%Theoretical , fine timestep to produce the curve in detail , Plot
%dtf=0.1
%t_thf=0:dtf:ttotal;
%a_thf=exp(-C*t_thf)*a(1);
%plot(t_thf,a_thf)
%axis([0. ttotal  -2*a(1) 2*a(1)])
%xlabel('time in seconds')
%ylabel('expectation number of neutrons')
%title('theoretical neutron decay')
%%Theoretical , simulation timestep for time comparison with simulation , Plot
%t_th=0:dt:ttotal;
%a_th=exp(-C*t_th)*a(1);
%plot(t_th,a_th)
%axis([0. ttotal  -2*a(1) 2*a(1)])
%xlabel('time in seconds')
%ylabel('expectation number of neutrons')
%title('theoretical neutron decay approximated by chords')
%Simulated minus Theoretical
t_th=0:dt:ttotal;
a_th=exp(-C*t_th)*a(1);
plot(t_th,a-a_th);
axis([0. ttotal  -2*a(1)*dtrat 2*a(1)*dtrat])
xlabel('time in seconds')
ylabel('sim. ex. number - theo. ex. number')
title('decay simulation error')
%Ratio of Simulated minus Theoretical to Theoretical
t_th=0:dt:ttotal;
a_th=exp(-C*t_th)*a(1);
plot(t_th,(a-a_th)./a_th);
axis([0. ttotal  -2*dtrat 2*dtrat])
%axis([0. ttotal  -0.002*dtrat 0.002*dtrat]) % for centered scheme
xlabel('time in seconds')
ylabel('(sim. ex. number - theo. ex. number)/theo. ex. number')
title('decay simulation proportional error')
