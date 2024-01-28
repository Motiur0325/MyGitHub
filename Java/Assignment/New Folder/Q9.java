import java.lang.Math;
import java.util.Scanner;

class Circle{
    double radius;
    Scanner sc=new Scanner(System.in);
    Circle(){
        radius=1.0;
    }
    Circle(double x){
        radius=x;
    }
    public double getRadius(){
        return radius;
    }
    public void setRadius(){
        System.out.print("\nEnter Radius :  ");
        radius=sc.nextDouble();
    }
    public double getArea(){
        return(Math.PI*radius*radius);
    }
}
class Cylinder extends Circle{
    double height;
    Scanner sc=new Scanner(System.in);
    Cylinder(){
        height=10;
    }
    Cylinder(double h,double r){
        height=h;
        radius=r;
    }
    public double getHeight(){
        return height;
    }
    public void setHeight(){
        System.out.print("\nEnter Height :  ");
        height=sc.nextDouble();
    }
    public double getCylinderArea(){
        return(2*Math.PI*radius*(radius+height));
    }
    public double getCylinderVolume(){
        return(Math.PI*radius*radius*height);
    }
}
public class Q9 {
    public static void main(String[] args) {
        Cylinder myObj1=new Cylinder();
        Cylinder myObj2=new Cylinder(10.0,5.0);
        Cylinder myObj3=new Cylinder();
        System.out.println("Radius :  "+myObj1.getRadius()+"  Height :  "+myObj1.getHeight()); 
        myObj1.setRadius();
        myObj3.setRadius();
        myObj3.setHeight();
        System.out.printf("Area :  %.2f  Volume :  %.2f\n",myObj1.getCylinderArea(),myObj1.getCylinderVolume());
        System.out.printf("Area :  %.2f  Volume :  %.2f\n",myObj2.getCylinderArea(),myObj2.getCylinderVolume());
        System.out.printf("Area :  %.2f  Volume :  %.2f\n",myObj3.getCylinderArea(),myObj3.getCylinderVolume());
    }
}
