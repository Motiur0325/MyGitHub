interface Shape{
    double area();
}
class Circle implements Shape{
    double r=10;
    @Override
    public double area(){
        return Math.PI*r*r;
    }
}
class Triangle implements Shape{
    double b=10,h=10;
    @Override
    public double area(){
        return (b*h)/2;
    }
}
class Rectangle implements Shape{
    double a=10,b=10;
    @Override
    public double area(){
        return a*b;
    }
}
public class Q15 {
    public static void main(String[] args) {
        Shape myCircle=new Circle();
        Shape myTriangle=new Triangle();
        Shape myRectangle=new Rectangle();
        System.out.printf("Area :  %.2f sq.units\n",myCircle.area());
        System.out.printf("Area :  %.2f sq.units\n",myTriangle.area());
        System.out.printf("Area :  %.2f sq.units\n",myRectangle.area());
    }
}