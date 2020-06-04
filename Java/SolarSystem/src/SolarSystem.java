import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
import processing.core.*;

/**
 *
 * @author dkruger
 */
public class SolarSystem extends PApplet {
  private ArrayList<Body> bodies;
  public SolarSystem(String filename) throws Exception {
    bodies = new ArrayList<>();
/    try {
      Scanner s = new Scanner(new File(filename));
  
      String header = s.nextLine();
      System.err.print(header);
      while (s.hasNextLine()) {
        String name = s.next();
        String orbits = s.next();
        double mass = s.nextDouble();
        //...
        bodies.add(new Body( ...... ));
        
      }
/*      
    } catch (Exception e) {
      e.printStackTrace();
    }
*/
  }
  public void settings() {
    size(1024,1024, P3D);
  }
  
  public void setup() {
    
  }
  
  public void add(Body b) {
    bodies.add(b);
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

