class Outer{
    int x=10;
    class Inner{
        void msg(){System.out.println("Data :  "+x);}
    }
}
public class Nested_Class1 {
    public static void main(String[] args) {
        Outer myOut=new Outer();
        Outer.Inner myIn=myOut.new Inner();
        myIn.msg();
    }
}
