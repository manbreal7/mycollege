/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
 * @author student
 */
/* Create a complex class. Use method overloading to find the sum.
 add(integer, complex number)
 add(complex number, complex number)
*/
class complex{
   void add(int a,int r,int i){
       System.out.println("sum is "+(r+a)+" +i"+i);
    }
   void add(int r1,int i1,int r2,int i2)
   {
       System.out.println("sum is "+(r1+r2)+" +i"+(i1+i2));
   }
}
public class q4 {
    public static void main(String args[]){
    complex cmp=new complex();
   cmp.add(2,1,3);
   cmp.add(2,1,4,6);
    }
}
