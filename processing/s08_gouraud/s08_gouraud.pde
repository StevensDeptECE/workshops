void setup() {
  size(1000,1000, P3D);
}

float a = 0;
void draw() {
  background(0);
  translate(width/2, height/2, 0);
  scale(1,-1,1);
  rotateX(a);
  beginShape();
  fill(255,0,0);
  vertex(-width/2,-height/2);
  fill(0,255,0);
  vertex(width/2,-height/2);
  fill(0,0,255);
  vertex(0,height/2);
  endShape();
  a += 0.01;
}
