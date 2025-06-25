import java.util.Scanner;

public class Factorial{
    public static int fact(int num){
        if(num==0||num==1){
            return 1;
        }
        else{
            return num*fact(num-1);
        }
    }
    public static int func(int num){
        if(num==0||num==1)return 1;
        int result=0,power=0;
        while(num/(int)Math.pow(10,power)!=0){
            power+=1;
        }
        for(int i=power-1;i>=0;i--){
            int temp=num/(int)Math.pow(10,i);
            result+=fact(temp);
            num=num%(int)Math.pow(10,i);
        }
        return result;
    }
    public static void main(String[] args){
        int n,k=0;
        Scanner sc=new Scanner(System.in);
        System.out.println();
        System.out.print("Enter value of n :  ");
        n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println();
        for(int i=0;i<n;i++){
            System.out.print("Enter number :  ");
            int num=sc.nextInt();
            int result=func(num);
            if(result==num){
                arr[k++]=num;
            }
            System.out.println();
        }
        System.out.print("Factorial are : ");
        for(int x=0;x<k;x++){
            System.out.print(arr[x]+" ");
        }
        System.out.println();
    }
}