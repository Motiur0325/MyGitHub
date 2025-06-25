import java.util.Scanner;

class Fibonacci{
    static int a=0,b=1;
    public static void Fibb(int x){
        if(x>0){
            int c=a+b;
            System.out.print(" "+c);
            a=b;
            b=c;
            Fibb(x-1);
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the no. of fibonacci numbers :  ");
        int n=sc.nextInt();
        System.out.print("Fibonacci :  "+a+" "+b);
        Fibb(n-2);        
        sc.close();
    }
}