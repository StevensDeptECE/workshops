import processing.core.*;

/**
 *
 * @author dkruger
 */
public class SolarSystem extends PApplet {
  public void settings() {
    size(1024,1024, P3D);
  }
  
  public void setup() {
    
  }
  
  public void draw() {
    //sphere(400);
    for (Body b : bodies) {
      b.draw(this);
    }
  }
  
  public static void main(String[] args) {  
    PApplet.main("SolarSystem");
  }
}

