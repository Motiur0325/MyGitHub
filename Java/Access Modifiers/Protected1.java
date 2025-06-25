class A{
    protected void msg(){System.out.println("Hello!!");}
}
class B extends A {
    public void msg(){System.out.println("Hello World!!");}
}
public class Protected1 {
    public static void main(String[] args) {
        A newB=new B();
        newB.msg();
        Object myObj=new B();
        System.out.println(myObj.getClass());
    }
}
