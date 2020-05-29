pkg load io
ibm = csvread('IBM.csv');
c = csv2cell('IBM.csv');

for i = 2:rows(c)
  ibm(i, 1) = datenum(c{i,1});
end

ibm(1,:) = []; # delete header bogus row

plot(ibm(:,1), ibm(:,2), '.');
datetick('x', 1); #format the dates on the x axis
