void setup() {
  size(1000,500);
  strokeWeight(0);
}

float a = 0;
float r = 10;
void draw() {
  translate(width/2, height/2);
  scale(20, -20);
  rotate(a);
  line(0,0, r,0);
  a += 0.01;
}
