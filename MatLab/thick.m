%200304AHCS345 thick : calculates weight by thickness, wt(k) ,
%	as differences of depths of bottoms of layers, depthi(k) . 
wt(1)=depthi(1) ;
for k=2:n
    wt(k)=depthi(k)-depthi(k-1);
end
