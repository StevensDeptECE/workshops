PShape earth;
void setup() {
  size(1000,1000, P3D);
  noStroke();
  earth = createShape(SPHERE, 500);
  PImage img = loadImage("jupiter.jpg");
  earth.setTexture(img);
  //sphereDetail(10);
}

float a = 0;
void draw() {
  background(0);
  translate(width/2, height/2,-500 );
  rotateY(a);
  shape(earth);
  a += 0.01;
}
