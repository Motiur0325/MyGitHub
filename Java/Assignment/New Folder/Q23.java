import java.lang.Exception;
import java.util.Scanner;

class InsufficientBalanceException extends Exception{
    InsufficientBalanceException(String msg){
        System.out.print(msg);
    }
}
class CheckAccount{
    double balance;
    CheckAccount(){
        balance=0.0;
    }
    void deposit(double money){
        balance+=money;
    }
    void withdraw(double money) throws InsufficientBalanceException{
        if(balance<money){
            throw new InsufficientBalanceException("Can't Withdraw the given Amount!!  ");
        }
        else{
            balance-=money;
        }
    }
    void show(){
        System.out.println("Current Balance :  "+balance);
    }
}
public class Q23 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        CheckAccount myObj1=new CheckAccount();       
        boolean myBool=true;
        while(myBool){
            System.out.print("\n1.Deposit\n2.Withdraw\n3.CheckBalance\t\tEnter Choice :  ");
            int ch=sc.nextInt();
            switch(ch){
                case 1: System.out.print("\nEnter the amount :  ");
                        myObj1.deposit(sc.nextDouble());
                        break;
                case 2: System.out.print("\nEnter the amount :  ");
                        try{
                            myObj1.withdraw(sc.nextDouble());
                        }
                        catch(Exception e){
                            System.out.println("{ "+e+" }");
                        }
                        finally{
                            System.out.println("\nCode ended without any exception interruption.!!");
                        }
                        break;
                case 3: myObj1.show();
                        break;
                default: myBool=false;
            }
        }
        sc.close();
    }
}
