//cube(30);
//cube(30, center=true);
//cube([10,20,30  ]);
//sphere(19);
//cylinder(20, 5, 10);
//cylinder(r=20,h=10);
//cylinder(r=20,h=10, center=true);

/*
translate([10,0,0]) {
  cube(30,center=true);
  sphere(19);
}
*/

/*
scale([2,1,5])
  sphere(10, $fn=100);
*/

//scale([2,1,5])
// cube(3);

//  cube([6,3,15]);

/*
rotate(90, [1,0,0]) 
cylinder(h=10,r=5, $fn=50);
*/

/*
difference() {
    cube(30,center=true);
    sphere(19);
    
}*/

/*union() {
    
}
*/

/*
$fn=100;
intersection() {
   sphere(30);
    translate( [0,0,50])
   sphere(30);   
}
*/


//square(10);
//circle(10);
//polygon([ [10,0], [0,20], [-6,8],[-20,0],[0,-20]  ]);

/*
linear_extrude(height= 2,scale=0.5)
translate([-12,-12])
    text("h",size=30);
*/


//linear_extrude(height=10, scale=1.5)
//    square(10,center=true);
/*
linear_extrude(height=10, scale=0.5, twist=360, $fn=30)
  square(10,center=true);
  */
  
  
/*
rotate_extrude(angle=45, $fn=30) {
      translate([10,0])
        square(10);
      
  }
*/

/*
  write a donut (torus) with radius R, with the thickness of the circle r
*/
module torus(R, r) {
  circle(r);    
}

//torus(30,10);

/*
minkowski() {
    cube(30);
    cylinder(r=5);
    
}*/

for (y=[0:10:50]) {
  for (x=[0,30,42]) {
    translate([x,y,0])
      cube(5);
    
  }
}


/*
challenges:
  ziggurat
  R2D2
  Android robot
  pipe(OD, thickness, L)
  gear(teeth, OD, toothdepth);

  build two gears that mesh properly

*/
  
  