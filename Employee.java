import java.util.Scanner;
class Employee1{

     String name;
     String city;
     double basic;
     double da;
     double hra;
    void getData() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter employee name: ");
        name = sc.nextLine();

        System.out.println("Enter city: ");
        city = sc.nextLine();

        System.out.println("Enter basic salary: ");
        basic = sc.nextDouble();

        System.out.println("Enter DA%: ");
        da = sc.nextDouble();

        System.out.println("Enter HRA%: ");
        hra = sc.nextDouble();
    }
  double calculateSalary() {
        return basic + (basic * da / 100) + (basic * hra / 100);
    }

   void display() {
        System.out.println("Employee name: " + name);
        System.out.println("City: " + city);
        System.out.println("Basic salary: " + basic);
        System.out.println("DA%: " + da);
        System.out.println("HRA%: " + hra);
        System.out.println("Total salary: " + calculateSalary());
    }
}

public class Employee {

    public static void main(String[] args) {
        Employee1 emp = new Employee1();
        emp.getData();
       //emp.calculateSalary();
        emp.display();
    }
}
