import java.util.Scanner;

class Try{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        char ch=sc.next().charAt(0);
        int c=(int)ch;
        int cd=Character.getNumericValue(ch);
        System.out.println("Int Value :  "+cd+"Char Value :  "+ch+"ASCII Value :  "+c);
    }
}