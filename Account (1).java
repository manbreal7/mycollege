import java.util.*;

class Account1 {

    String name;
    int accno;
    String typeofacc;
    float balance;
}

public class Account {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Account1 a = new Account1();

        System.out.println("enter name of person");
        a.name = sc.next();
        System.out.println("enter acc.no.");
        a.accno = sc.nextInt();
        System.out.println("enter type of account");
        a.typeofacc = sc.next();
        System.out.println("enter account balance");
        a.balance = sc.nextFloat();
        while (1 < 100) {
            System.out.println("enter 1-deposit 2-display 3-compute interest 4-widthdraw 5-Check for penalty 6-Exit");
            int op = sc.nextInt();
            if (op == 6) {
                break;
            }
            switch (op) {
                case 1:
                    System.out.println("enter amount");
                    float amt = sc.nextFloat();
                    a.balance += amt;
                    System.out.println(a.balance);

                    break;
                case 2:
                    System.out.println(a.balance);
                    break;
                case 3:
                    if("current".equals(a.typeofacc)){
                        System.out.println("interest is 0");
                    }
                    else{
                    float interest = (float) (a.balance * .12);
                    System.out.println("Interest is" + interest);
                    }
                    break;
                case 4:
                    System.out.println("enter amount to withdraw");
                    float gone = sc.nextFloat();
                    a.balance -= gone;
                    System.out.println(a.balance);
                    break;
                case 5:
                    if ("savings".equals(a.typeofacc) && a.balance < 5000) {

                        System.out.println("service charge is" + 500);
                    } else {
                        System.out.println("no service charge");
                    }

                    break;
            }
        }
    }

}
