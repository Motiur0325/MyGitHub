package Fibbo;

public class MyFibb{
    public static int a=0,b=1;
    public static void Fibb(int x){
        if(x>0){
            int c=a+b;
            System.out.print(" "+c);
            a=b;
            b=c;
            Fibb(x-1);
        }
    }
}