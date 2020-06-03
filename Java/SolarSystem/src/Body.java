/**
 *
 * @author dkruger
 */
public class Body {
  private String name;
  private PImage img;
  private PShape s;
  public Body(String name, String image, float radius, float orbitalDistance, float orbitTime, float rotationTime) {
    this.name = name;
    //...
  }
  public void draw(PApplet p) {
    // translate to the right place
    // rotate to the right orientation
    p.shape(s);
  }
  
}
