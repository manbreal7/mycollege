// Objects are passed by reference.
class Test
{ 
    int a, b;
Test(int i, int j)
{ a = i;
b = j;
}
// pass an object
void meth(Test o)
{
o.a = o.a+ 10;
o.b = o.b - 10;
}
}
class CallByRef
{
public static void main(String args[])
{
Test ob = new Test(15, 20);
System.out.println("ob.a and ob.b before call: " +ob.a + " " + ob.b);
ob.meth(ob);
System.out.println("ob.a and ob.b after call: " +ob.a + " " + ob.b);
}
}