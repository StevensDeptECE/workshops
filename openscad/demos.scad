/*
cube(30);
sphere(15);
cylinder(r=10,h=20);

*/

// translate([1,2,3])
/*
scale([2,0.5,1])
    sphere(15);
*/

//rotate(-45, [1,0,0])
//    cube(10);
/*    
    rotate(-45, [1,1,1])
    cube(10);
    
*/
/*
difference() {
    cube(30, center=true);
    sphere(19);
}

union() {
    cube(30);
    translate([10,10,10])
      cube(30);
}
*/

/*
intersection() {
    sphere(10);
    translate([13,0])
      sphere(10);
}
*/
$fn=20;
tableRadius = 30;
sides=6;
legLen = 20;
dt = 360/sides; //angle per side

p= [for (s=[0:sides]) [tableRadius*cos(s*dt), tableRadius*sin(s*dt)] ];
linear_extrude(height=3)
    polygon(p);
for (s=[0:sides-1]) {
    translate([tableRadius*cos(s*dt), tableRadius*sin(s*dt)])
        cylinder(r=2,h=20);
}


