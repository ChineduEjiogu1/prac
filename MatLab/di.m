%200302CS345 di : given an array of depths "depth" calculates an array of
%	n interface depths "depthi" using fact that 
%	depth(k+1) is midway between depthi(k) and depthi(k+1) .
%	As Mr. Ejiogu found this yields depthi(k+1)=2*depth(k+1) - depthi(k) .
	dimen = size(depth)
	n = dimen(1)
	depthi(1) = 2*depth(1);
	for k=1:n-1
	    depthi(k+1)=2*depth(k+1)-depthi(k);  
	end
	depthi=depthi' ;
