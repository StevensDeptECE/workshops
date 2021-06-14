a=[0.0000   6.0000
  0.0000   0.0000
  3.0000   0.0000
  4.0000   1.0000
  6.0000   1.0000
  8.0000   0.0000
 12.0000   0.0000
 13.0000   2.0000
  8.0000   2.0000
  8.0000   4.0000
 11.0000   4.0000
 11.0000   6.0000
  6.0000   6.0000
  4.0000   3.0000
  2.0000   6.0000
];

at=[
   2.0000,  6.0000,     0.0000,  6.0000,     0.0000,  0.0000
  0.0000,  0.0000,     3.0000,  0.0000,     4.0000,  1.0000
  6.0000,  1.0000,     8.0000,  0.0000,    12.0000,  0.0000
 12.0000,  0.0000,    13.0000,  2.0000,     8.0000,  2.0000
  8.0000,  4.0000,    11.0000,  4.0000,    11.0000,  6.0000
 11.0000,  6.0000,     6.0000,  6.0000,     4.0000,  3.0000
  4.0000,  3.0000,     2.0000,  6.0000,     0.0000,  0.0000
  6.0000,  1.0000,    12.0000,  0.0000,     8.0000,  2.0000
  8.0000,  4.0000,    11.0000,  6.0000,     4.0000,  3.0000
  4.0000,  3.0000,     0.0000,  0.0000,     4.0000,  1.0000
  4.0000,  1.0000,     6.0000,  1.0000,     8.0000,  2.0000
  8.0000,  2.0000,     8.0000,  4.0000,     4.0000,  3.0000
  4.0000,  3.0000,     4.0000,  1.0000,     8.0000,  2.0000
];

b=[
-157.7211  21.4684
-157.7212  21.4688
-157.7216  21.4690
-157.7217  21.4699
-157.7217  21.4700
-157.7213  21.4703
-157.7211  21.4703
-157.7207  21.4703
-157.7206  21.4702
-157.7204  21.4702
-157.7202  21.4703
-157.7199  21.4704
-157.7196  21.4708
-157.7193  21.4709
-157.7190  21.4707
-157.7186  21.4707
-157.7185  21.4707
-157.7183  21.4706
-157.7183  21.4705
-157.7184  21.4704
-157.7183  21.4702
-157.7181  21.4697
-157.7182  21.4697
-157.7183  21.4697
-157.7185  21.4696
-157.7191  21.4694
-157.7196  21.4689
-157.7200  21.4686
-157.7208  21.4685
-157.7210  21.4684
-157.7211  21.4684
]


bt=[
-157.7207, 21.4703,   -157.7206, 21.4702,   -157.7204, 21.4702
-157.7202, 21.4703,   -157.7199, 21.4704,   -157.7196, 21.4708
-157.7193, 21.4709,   -157.7190, 21.4707,   -157.7186, 21.4707
-157.7183, 21.4705,   -157.7184, 21.4704,   -157.7183, 21.4702
-157.7182, 21.4697,   -157.7183, 21.4697,   -157.7185, 21.4696
-157.7185, 21.4696,   -157.7191, 21.4694,   -157.7196, 21.4689
-157.7200, 21.4686,   -157.7208, 21.4685,   -157.7210, 21.4684
-157.7207, 21.4703,   -157.7204, 21.4702,   -157.7202, 21.4703
-157.7193, 21.4709,   -157.7186, 21.4707,   -157.7185, 21.4707
-157.7183, 21.4705,   -157.7183, 21.4702,   -157.7181, 21.4697
-157.7181, 21.4697,   -157.7182, 21.4697,   -157.7185, 21.4696
-157.7185, 21.4696,   -157.7196, 21.4689,   -157.7200, 21.4686
-157.7211, 21.4703,   -157.7207, 21.4703,   -157.7202, 21.4703
-157.7181, 21.4697,   -157.7185, 21.4696,   -157.7200, 21.4686
-157.7211, 21.4703,   -157.7202, 21.4703,   -157.7196, 21.4708
-157.7213, 21.4703,   -157.7211, 21.4703,   -157.7196, 21.4708
];

plot(a(:,1), a(:,2), 'k', 'LineWidth', 5)
hold on
for i=1:rows(at)
  plot(at(i,[1,3,5]), at(i,[2,4,6]), 'r')
end

figure

plot(b(:,1), b(:,2), 'k', 'LineWidth', 5)
hold on
for i=1:rows(bt)
  plot(bt(i,[1,3,5]), bt(i,[2,4,6]), 'r')
end

