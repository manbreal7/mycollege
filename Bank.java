/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
class Bank1 {

    private double rate;
    //private double interest;

    public Bank1(double rate1) {
        this.rate= rate1;
    }

    public double Rate2() {
        //this.interest=interest;
        // interest=(1000*3*rate)/100;
        return rate;
        
    }
     public double cal(double p, int years) {
        return (p * rate *years)/100;

}}

class SBI extends Bank1 {

    public SBI() {
        super(8);
    }
}

class ICICI extends Bank1 {

    public ICICI() {
        super(7);
    }
}

class AXIS extends Bank1 {

    public AXIS() {
        super(9);
    }
}

public class Bank {

    public static void main(String[] args) {
        Bank1 b;

        b = new SBI();
          double interest = b.cal(100000, 5);
        System.out.println("SBI rate of interest: " + b.Rate2());
        System.out.println("Amount of SBI "+interest);

        b = new ICICI();
        interest = b.cal(100000, 5);
        System.out.println("ICICI rate of interest: " + b.Rate2());
         System.out.println("Amount of ICICI "+interest);
        b = new AXIS();
        interest = b.cal(100000, 5);
        System.out.println("AXIS rate of interest: " + b.Rate2());
         System.out.println("Amount of AXIS "+interest);
    }
}
