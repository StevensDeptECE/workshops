void setup() {
  size(600,400);
}

float x = 0, y = 0, dx = 1.2, dy = 3.14;

//final int n = 10;
//float[] x = new float[n], y = new float[n], dx = new float[n], dy = new float[n];
final int W = 30, H = 40;
void draw() {
  background(0,0,255 );
  fill(255,0,0);
  rect(x,y,W,H);
  x += dx;
  y += dy;
 
  if (x < 0 || x >= width - W) {
    dx = -dx;
  }
  if (y < 0 || y >= height - H) {
    dy = -dy;
  }

}
