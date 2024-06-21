/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
 * @author student . Create a Time class that has separate integer member data
 * for hours, minutes and seconds. One constructor should initialize these data
 * to zero and another should initialize to fixed value. A method should display
 * time in hh:mm:ss format. Finally a method should add 2 objects of time passed
 * as argument.
 */

 class Time1 {
    int hours;
    int minutes;
    int seconds;

    Time1() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
     Time1(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }
    public String toString() {
        return String.format("%d:%02d:%02d", hours, minutes, seconds);
    }
  void add(Time1 time1, Time1 time2) {
        hours = time1.hours + time2.hours;
        minutes = time1.minutes + time2.minutes;
        seconds = time1.seconds + time2.seconds;

        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
    }
}

public class Time {

    public static void main(String args[]) {
        Time1 time1 = new Time1(1, 59, 34);
         Time1 time2 = new Time1(10, 05, 32);
         Time1 time3 = new Time1();
        time3.add(time1, time2);
        System.out.println(time3.toString());

    }
}
