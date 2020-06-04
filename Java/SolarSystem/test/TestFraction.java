
/**
 *
 * Testing: JUnit
 * Continuous Integration: Jenkins, Travis, etc.
 * Every time you check code into your gitub repo, Travis (or other CI) will automatically build and test
 * https://www.joelonsoftware.com/2000/08/09/the-joel-test-12-steps-to-better-code/
 * 
 * @author dkruger
 */
public class TestFraction {
  public static void main(String[] args) {
    Fraction a = new Fraction(1, 2);
    Fraction b = new Fraction(1, 3);
    Fraction c = a.add(b); // 5/6
    System.out.println(c);
    System.out.println(new Fraction(2,2).add(new Fraction(3,3)));
    
    
  }
}
