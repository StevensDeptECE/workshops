import static java.lang.Math.*;
/**
 *
 * @author dkruger
 */
public class Vec3d {
  private double x, y, z;
  public Vec3d(double x, double y, double z) {
    this.x = x; this.y = y; this.z = z;
  }
  
  public Vec3d add(Vec3d r) {
    return new Vec3d(x + r.x, y + r.y, z + r.z);
  }

  public Vec3d sub(Vec3d r) {
    return new Vec3d(x - r.x, y - r.y, z - r.z);
  }
  
  public Vec3d mult(double s) {
     return new Vec3d(s * x, s * y, s * z); 
  }
  public double mag() {
    return sqrt(x*x+y*y+z*z);
  }
  
  public String toString() {
    return "[" + x + ',' + y + "," + z + ']'; 
  }
  public static void main(String[] args) {
     Vec3d v1 = new Vec3d(1.0, 2.5, 3.2);
     System.out.println(v1);
     Vec3d v2 = new Vec3d(2.5, 1.2, 4.5);
     Vec3d v3 = v1.add(v2); // Vec3d.add(v1, v2)
     Vec3d v4 = v1.sub(v2);
     double dist = v4.mag();
     System.out.println(v3);
     System.out.println(v4);
     System.out.println(v4.mult(2));
     System.out.println(dist);

     //G m1*m2 / (dist squared)
    
  }

}
