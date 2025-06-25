import java.util.Scanner;
class Series{
    int n,a,b;
    void Accept(){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the no. of terms :  ");
        n=sc.nextInt();
        sc.close();
    }
    void Assign(){
        a=0;
        b=1;
    }
    void Generate(){
        System.out.print("Fibonacci Series :  ");
        for(int i=0;i<n;i++){
            System.out.print(a+ " ");
            b=a+b;
            a=b-a;
        }
    }
}

public class Fibonacci {
    public static void main(String[] args) {
        Series myObj1=new Series();
        myObj1.Accept();
        myObj1.Assign();
        myObj1.Generate();
    }
}
