void setup() {
  size(600,400);
  frameRate(1);
}

int x = 0, y = 0;
void draw() {
//  background(0,0,255 );
  fill(0,0,255,10);
  rect(0,0,width,height);
  fill(255,0,0);
  //line(0,0, 300,400);
  rect(x,y,30,40);
  x+=7;
  if (x >= 600 ) {
    x = 0;
  }
}
