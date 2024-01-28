class A{
    A(){
        System.out.println("Hello");
    }
}
class ObjectClass{
    public static void main(String[] args) {
        Object myObj=new A();
        System.out.println(myObj.getClass());
        System.out.println(myObj.hashCode());
    }
}