import java.util.*;

public class stack{
	static int pop(ArrayList<Integer> S){
		int val=0;
		if(S.size()==0){
			System.out.println("Stack Underflow");
			return val;
		}else{
			val=S.get(S.size()-1);
			S.remove((int)(S.size())-1);
		}
		return val;
	}
	static void pushStack(ArrayList<Integer> S,int x){
		S.add(x);
	}
	public static void main(String[] args){
		int ch,n;
		ArrayList<Integer> myStack=new ArrayList<Integer>();
		Scanner myScan=new Scanner(System.in);
		boolean myCheck=true;
		while(myCheck!=false){
			System.out.print("\n1.Push\n2.Pop\n3.Display\n4.Exit\n\nEnter Choice :  ");
			ch=myScan.nextInt();
			switch(ch){
				case 1 : System.out.print("Enter data :  ");
					 n=myScan.nextInt();
					 pushStack(myStack,n);
					 break;
				case 2 : System.out.println("\nPopped value :  "+pop(myStack));
					 break;
				case 3 : System.out.print("\nStack :  ");
					 for(int i : myStack){
					 	System.out.print(i+" ");
					 }
					 break;
				default : myCheck=false;
			}
		}
	}
}