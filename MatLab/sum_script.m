temp = [5, 6, 6, 7, 8, 10, 17, 19, 20, 20];
dimen = size(temp);
n=dimen(2);

sum = 0;

for i=1 : n
  sum = sum + temp(i);  
end

average = sum / n;
