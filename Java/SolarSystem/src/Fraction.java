/**
 *
 * @author dkruger
 */
public class Fraction {
  private int num, den;
  public Fraction(int n, int d) {
    num = n; den = d;
  }
  /*
  
     this                 right
         num = 1               num = 1
         den = 2               den = 3
  
  */
  
  public Fraction add(Fraction right) {
//    return new Fraction (this.num*right.den + right.num*this.den, this.den * right.den);
    return new Fraction (num*right.den + right.num*den, den * right.den);
  }
      
  public String toString() {
    return num + "/" + den;
  }
  
  public static void main(String[] args) {
    System.out.println("testing....");
    int x; // create primitive type
    Fraction a = new Fraction(1,2); // 1/2 needs "new"
    
    Fraction b = new Fraction(1,3); // 1/3
    Fraction c = a.add(b);
    System.out.println(c);
    Fraction d = new Fraction(2,2); // 2/2
    System.out.println(d.add(d)); // 2/2 + 2/2  = 8/4
  }
  
}
