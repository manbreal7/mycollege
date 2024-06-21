// Simple types are passed by value.
class Test
{ void meth(int b)
{ b = b+25;
}
}
class CallByValue
{ public static void main(String args[])
{ Test ob = new Test();
int a = 25;
System.out.println("value of a before call: " + a );
ob.meth(a);
System.out.println("value of a after call " +a); 
} }