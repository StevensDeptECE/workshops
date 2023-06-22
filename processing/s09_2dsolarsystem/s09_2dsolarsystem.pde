void setup() {
  size(1000,1000);
  rectMode(CENTER);
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
  //sun
  fill(255,255,0);
  float cx = 100, cy = 0;
  translate(cx, cy);
  circle(0,0,100);

//demonstrate an exaggerated elliptical orbit for earth aligned to the origin
  float xearth = cos(orbitAngleEarth)*earth0, yearth = sin(orbitAngleEarth)*earth1;
  float orbitalRadiusEarth = sqrt(xearth*xearth + yearth*yearth);
  fill(255); // set the color of "earth" to white
  pushMatrix();
  rotate(orbitAngleEarth);     // rotate earth to correct place in orbit
  translate(orbitalRadiusEarth,0);  // translate out by distance from sun
  rotate(-orbitAngleEarth);    // unrotate so it is always at a constant angle
  rotate(rotateEarth);     // rotate earth to correct rotation for "day"
  
  rect(0,0, 50,50);
  popMatrix();
  orbitAngleEarth += deltaAngle; 
  rotateEarth += 365.25* deltaAngle;
  
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
