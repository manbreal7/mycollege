/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
 * @author student
 * 
 */
class number{
 private double d;

 number(double a){
    this.d=a;
}
boolean iszero(){
if(d==0)
return true;
else
     return false;
}
boolean ispos(){
if(d>0)
return true;
else
     return false;
}
boolean isneg(){
if(d<0)
return true;
else
     return false;
}
boolean isodd(){
if(d%2!=0)
return true;
else
     return false;
}
boolean iseven(){
if(d%2==0)
return true;
else
     return false;
}
boolean isprime(){
    if(d<=1){
        return false;
    }
    if(d==2){
        return true ;
    }
    for(int i=2;i<=d/2;i++){
        if(d%2==0){
            return false;
        }
    }
    return true;
}
boolean isarmstrong(){
    
    int sum=0;
    for(int i=1;i<d;i++){
        if(d%i==0){
            sum+=i;
        }
    }
    if (sum==d){
        return true;
    }
    else
        return false;
}
}
public class q5number {
    public static void main(String args[]){
        number num=new number(28);
        System.out.println("Is number zero?"+num.iszero());
         System.out.println("Is number pos?"+num.ispos());
          System.out.println("Is number neg?"+num.isneg());
           System.out.println("Is number odd?"+num.isodd());
            System.out.println("Is number even?"+num.iseven());
             System.out.println("Is number prime?"+num.isprime());
              System.out.println("Is number armstrong?"+num.isarmstrong());
              
         
    }
}
