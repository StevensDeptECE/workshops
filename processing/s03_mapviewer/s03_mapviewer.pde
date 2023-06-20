PImage img;
void setup() {
  size(2000,1200);
  img = loadImage("worldmap.png");
}

int x = 0,y = 0;
void draw() {
  background(128);
  image(img, x, y);
}

final int dx = 50, dy = 50;
void keyPressed() {
  switch(keyCode) {
    case 'A': // left
      x -= dx;
      break;
    case 'D':// right
      x += dx;
      break;
    case 'W':
      y -= dy;
      break;
    case 'S':
      y += dy;
      break;
  }
}

void mousePressed() {
  
}
