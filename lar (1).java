public class lar {

  public static void main(String[] args) {
    int a = 10;
    int b = 20;
    int c = 30;

    int l = a > b ? (a > c ? a : c) : (b > c ? b : c);

    int s = a < b ? (a < c ? a : c) : (b < c ? b : c);

    System.out.println("The largest number is " + l);
    System.out.println("The smallest number is " + s);
  }
}
