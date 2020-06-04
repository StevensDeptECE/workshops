//list "comprehension"

module regularPolygon(n, r) {
    da = 360/n;
    a=[for (t=[0:da:360]) [ r*cos(t), r*sin(t)  ] ] ;
    polygon(a);
}

/*
difference() {
    linear_extrude(height=1)
        regularPolygon(7, 30);
//    cube(4, center=true);
    translate([-10,-5, .2])
    linear_extrude(height=1)
        text("DK", font="Times");
}
*/

//square(10);
//circle(5);
//square([10,20]);
/*
linear_extrude(height=30, twist=360, scale=0)
    square(10, center=true);

*/

rotate_extrude($fn=5) {
    translate([10,0])
        square(10);
}
