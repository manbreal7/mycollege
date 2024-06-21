/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
class ObjectCounter {

   static int count;

    public ObjectCounter() {
        count++;
    }

    public static int getCount() {
        return count;
    }

    public static void main(String[] args) {
        ObjectCounter obj1 = new ObjectCounter();
        ObjectCounter obj2 = new ObjectCounter();
        ObjectCounter obj3 = new ObjectCounter();
         ObjectCounter obj4 = new ObjectCounter();

        System.out.println("The number of objects created is: " + ObjectCounter.getCount());
    }
}

