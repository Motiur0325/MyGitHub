class Shape{
    public double area(){
        return 1.0;
    }
}
class Circle extends Shape{
    double r=10;
    @Override
    public double area(){
        return Math.PI*r*r;
    }
}
class Triangle extends Shape{
    double b=10,h=10;
    @Override
    public double area(){
        return (b*h)/2;
    }
}
class Rectangle extends Shape{
    double a=10,b=10;
    @Override
    public double area(){
        return a*b;
    }
}
public class Q14 {
    public static void main(String[] args) {
        Circle myCircle=new Circle();
        Triangle myTriangle=new Triangle();
        Rectangle myRectangle=new Rectangle();
        Shape ref;
        ref=myCircle;
        System.out.println("Area :  "+ref.area()+"sq.units");
        ref=myTriangle;
        System.out.println("Area :  "+ref.area()+"sq.units");
        ref=myRectangle;
        System.out.println("Area :  "+ref.area()+"sq.units");
    }
}
