import java.util.*;

public class Q3 {
    static int top=-1;
    static int MAX=5;
    public static void stackPush(String[][] S){
        top++;
        Scanner sc=new Scanner(System.in);
        if(top==MAX){
            System.out.println("\nStackOverflow.");
        }
        else{
            System.out.print("\nEnter Student Name :  ");
            S[top][0]=sc.nextLine();
            System.out.print("\nEnter Student Roll :  ");
            S[top][1]=sc.nextLine();
        }
    }
    public static void stackPop(String[][] S){
        if(top==-1){
            System.out.println("\nStackUnderflow");
        }
        else{
            System.out.println("\nPopped value : [Name : "+S[top][0]+"] [Roll : "+S[top][1]+"]");
            S[top][0]=null;
            S[top][1]=null;
            top--;
        }
    }
    public static void stackDisplay(String[][] S){
        System.out.println("\nStack\n--------\n--------");
        for(int x=top;x>=0;x--){
            System.out.println("{ Name : "+S[x][0]+", Roll : "+S[x][1]+"}");
        }
        System.out.println();
    }
    public static void stackTop(String[][] S){
        System.out.println("\nTop :  { Name : "+S[top][0]+", Roll : "+S[top][1]+"}");
    }
    public static void stackCount(String[][] S){
        System.out.println("\nStack Count :  "+(top+1));
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        boolean myBool=true;
        String[][] myStack=new String[MAX][2];
        while(myBool){
            System.out.print("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Top\n5.Count\t\tEnter Choice :  ");
            int ch=sc.nextInt();
            switch(ch){
                case 1: stackPush(myStack);
                        break;
                case 2: stackPop(myStack);
                        break;
                case 3: stackDisplay(myStack);
                        break;
                case 4: stackTop(myStack);
                        break;
                case 5: stackCount(myStack);
                        break;
                default : myBool=false;
            }
        }
        sc.close();
        System.out.println("\nInvalid Input!\nTry Again!!");
    }
}
