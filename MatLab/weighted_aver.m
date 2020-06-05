tem = [5, 6, 6, 7, 8, 10, 17, 19, 20, 20];
wt = [375, 249, 166, 111, 74, 49, 33, 22, 15, 10];

%temsum = 0;
%wtsum = 0;

dimen = size(tem);
n = dimen(2);

%for i=1:n
    %temsum = temsum + wt * tem(i);
    %wtsum = wtsum + wt(i);
%end

%wtsum = sum(wt. *tem);
wt = sum(wt. *tem)./sum(wt);
%wtav = temsum/wtsum;




