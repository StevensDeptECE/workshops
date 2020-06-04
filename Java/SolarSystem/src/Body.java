/**
 *
 * @author dkruger
 */
public class Body {
  private String name;
  private PImage img;
  private PShape s;
  private double radius;


  private final static double G = 6.57e-11;
  private double mass;
  private Vec3d pos;
  private Vec3d v;
  private Vec3d a;
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
