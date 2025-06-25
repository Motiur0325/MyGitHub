import java.lang.Exception;
class NegativeNumberException extends Exception{
    NegativeNumberException(String msg){
        System.out.print(msg);
    }
}
public class Q21{
    public static void fact(int n) throws NegativeNumberException{
        if(n<0){
            throw new NegativeNumberException("Can't Find the Factorial of a Negative Number! ");
        }
        else{
            if(n==0){
                System.out.println("Factorial :  1");
            }
            else{
                for(int i=n-1;i>=1;i--){
                    n=n*i;
                }
                System.out.println("Factorial :  "+n);
            }
        }
    }
    public static void main(String[] args) {
        try{
            fact(6);
            fact(-3);
        }
        catch(Exception e){
            System.out.println("{"+e+"}");
        }
    }
}