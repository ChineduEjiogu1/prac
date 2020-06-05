dt=0;
t_th=0:dt:ttotal;
a_th=exp(-C*t_th)*a(1);
plot(t_th,(a-a_th)./a_th);
axis([0. ttotal  -2*dtrat 2*dtrat])
%axis([0. ttotal  -0.002*dtrat 0.002*dtrat]) % for centered scheme
xlabel('time in seconds')
ylabel('(sim. ex. number - theo. ex. number)/theo. ex. number')
title('decay simulation proportional error')