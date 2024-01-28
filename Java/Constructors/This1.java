class Student{
    String name;
    int roll;
    int age;
    Student(){
        System.out.println("Hello Student");
    }
    Student(int roll,String name){
        this.name=name;
        this.roll=roll;
    }
    Student(int a){
        this();
        age=a;
    }
    void showName(){
        System.out.println("Hello "+name);
    }
    void showRoll(){
        this.showName();
        System.out.println("Hello "+roll);
    }
}
public class This1 {
    public static void main(String[] args) {
        Student Ob1=new Student(1,"Franco");
        Student Ob2=new Student(17);
        Ob2.showRoll();
        Ob1.showName();
        Ob1.showRoll();
    }
}
