import java.util.Scanner;
class student
{
String name;
int reg_no,age;
student()
{
name="";
reg_no=0;
age=0;
}
}
class UG extends student
{
int sem,fee;
UG(String n, int r, int a)
{
name=n;
reg_no=r;
age=a;
sem=1;
fee=335000;
}
void display()
{
System.out.println("Student name: "+name);
System.out.println("Registration number: "+reg_no);
System.out.println("Age: "+age);
System.out.println("Semester: "+sem);
System.out.println("Fees: "+fee);
}
}
class PG extends student
{
int sem,fee;
PG(String n, int r, int a)
{
name=n;
reg_no=r;
age=a;
sem=1;
fee=250000;
}
void display()
{
System.out.println("Student name: "+name);
System.out.println("Registration number: "+reg_no);
System.out.println("Age: "+age);
System.out.println("Semester: "+sem);
System.out.println("Fees: "+fee);
}
}
class details
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the number of UG students");
int x=sc.nextInt();
UG ob[]=new UG[x];
System.out.println("Enter the number of PG students");
int y=sc.nextInt();
PG obj[]=new PG[y];
System.out.println("Enter the details of UG students");
for(int i=0;i<x;i++)
{
String n=sc.next();
int r=sc.nextInt();
int a=sc.nextInt();
ob[i]=new UG(n,r,a);
}
System.out.println("Enter the details of PG students");
for(int i=0;i<y;i++)
{
String n=sc.next();
int r=sc.nextInt();
int a=sc.nextInt();
obj[i]=new PG(n,r,a);
}
System.out.println("\n***DETAILS OF UG STUDENTS***\n");
for(int i=0;i<x;i++)
{
ob[i].display();
System.out.println();
}
System.out.println("\n***DETAILS OF PG STUDENTS***\n");
for(int i=0;i<y;i++)
{
obj[i].display();
System.out.println();
}
}
}