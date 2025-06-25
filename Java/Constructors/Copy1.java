class CopyConstructor1{
    int id;
    int s;
    String name;
    CopyConstructor1(int i,String s){
        id=i;
        name=s;
    }
    CopyConstructor1(CopyConstructor1 C){
        id=C.id;
        name=C.name;
        s=100;
    }
    void show(){
        System.out.println(id+" "+name+" : Score - "+s);
    }
}
class Copy1{
    public static void main(String[] args) {
        CopyConstructor1 myObj1=new CopyConstructor1(1010, "Franco");
        CopyConstructor1 myObj2=new CopyConstructor1(myObj1);
        myObj1.show();
        myObj2.show();
    }
}