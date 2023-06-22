/*
  do every parameter of the body in  here:
  location (x,y,z)
  size
  image
  axis of rotation
  speeds of orbit, rotation, etc.
  
  elliptical if you want
*/
class Body {
  
}

PShape sun, earth, moon, mars;
void setup() {
  size(1000,1000, P3D);
  noStroke();
  sun = createShape(SPHERE, 400);
  sun.setTexture(loadImage("sun.jpg"));
  
  earth = createShape(SPHERE, 300);
  earth.setTexture(loadImage("earth.jpg"));
  
  moon = createShape(SPHERE, 200);
}

final float earth0 = 200, earth1 = 300;
float orbitAngleEarth = 0;
float rotateEarth = 0;
float orbitalRadiusMars = 360;
float orbitAngleMars = 0;
float rotateMars = 0;
final float deltaAngle = 0.003;
void draw() {
  background(0);
  translate(width/2,height/2);
  scale(1,-1);
  
  shape(sun);
  
  
//demonstrate an exaggerated elliptical orbit for earth aligned to the origin
  float xearth = cos(orbitAngleEarth)*earth0, yearth = sin(orbitAngleEarth)*earth1;
  float orbitalRadiusEarth = sqrt(xearth*xearth + yearth*yearth);
  fill(255); // set the color of "earth" to white
  pushMatrix();
  rotateY(orbitAngleEarth);     // rotate earth to correct place in orbit
  translate(orbitalRadiusEarth,0);  // translate out by distance from sun
  rotateY(-orbitAngleEarth);    // unrotate so it is always at a constant angle
  rotateX(23.5*PI/180); // apply earth axis
  rotateY(rotateEarth);     // rotate earth to correct rotation for "day"
  shape(earth);  
  popMatrix();
  orbitAngleEarth += deltaAngle; 
  rotateEarth += 365.25* deltaAngle;
  pushMatrix();
  // TODO: do the moon!
  popMatrix();  
  pushMatrix();
  fill(180,20,40);

  rotate(orbitAngleMars);
  translate(orbitalRadiusMars,0);
  rotate(-orbitAngleMars);
  rotate(rotateMars);     // rotate mars to correct orientation for martian "day"
  rect(0,0, 20,20);
  popMatrix();
  orbitAngleMars += deltaAngle*.55;
  rotateMars += deltaAngle * 340;
}
