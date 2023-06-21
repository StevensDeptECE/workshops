void setup() {
  size(1000,1000, P3D); 
}

float a = 0;
void draw() {
  background(0);
  translate(width/2, height/2,-1000 );
  //noStroke();
  rotateY(a);
  scale(2,0.5,0.2);
  sphere(500);
  a += 0.01;
}
