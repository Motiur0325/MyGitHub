class Car{
    void run(){System.out.println("Car is running....");}
}
class Supra extends Car{
    void run(){System.out.println("Speed is 180 mph.");}
}
class Test_Override1{
    public static void main(String[] args) {
        Car myCar1=new Supra();
        myCar1.run();
        Car myCar3,myCar2=new Car();
        myCar2.run();
        myCar3=new Supra();
        myCar3.run();
    }
}