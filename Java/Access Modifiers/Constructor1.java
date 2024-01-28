class A{
    private A(){
        System.out.println("Hello A !!");
    }
    A(int x){
        this();
        System.out.println("Hello A !!");
    }
}
class Constructor1{
    public static void main(String args[]){
        // A ob=new A();
        A obj=new A(10);
    }
}