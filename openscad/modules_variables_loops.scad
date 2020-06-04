module holycube(cubeSize, r) {
    difference() {
        cube(cubeSize, center=true);
        sphere(r);
    }
}

module holyCubeAssembly(centerCubeSize, centerR, sideCubeDelta, sideRDelta) { 
sideCubeSize = centerCubeSize + sideCubeDelta;
sideR = centerR + sideRDelta;    
holycube(centerCubeSize,centerR);
translate([centerCubeSize,0])
    holycube(sideCubeSize, sideR);
translate([-centerCubeSize,0])
    holycube(sideCubeSize, sideR);
}

/*holyCubeAssembly(30, 19, 2, 3);
translate([0,28])
    holyCubeAssembly(30, 19, 2, 3);

*/
/*
for (z = [10:10:100]) {
  translate([0,0,z])
    for (y = [10:10:100]) {
        translate([0,y])
            for (x = [10:10:100]) {
                translate([x,0])
                    cube(8);
            }
    }
}
*/

for (a=[0:22.5:360-22.5]) {
    rotate(a, [1,0,0])
        cylinder(r=2,h=20, $fn=30);
}









