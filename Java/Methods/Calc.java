import java.util.Scanner;

public class Calc{
	static int myAdd(int x,int y){
		return x+y;
	}
	static int mySub(int x,int y){
		return x-y;
	}
	static int myMul(int x,int y){
		return x*y;
	}
	static float myDiv(float x,float y){
		return x/y;
	}
	public static void main(String[] args){
		int m,n;
		boolean myCheck=true;
		Scanner myObj=new Scanner(System.in);
		float result=0;
		do{
			System.out.println("1.ADD\n2.SUB\n3.MUL\n4.DIV\n5.EXIT\n\nEnter Choice : ");
			int ch=myObj.nextInt();
			switch(ch){
				case 1 : System.out.println("Enter First No. :  ");
					 m=myObj.nextInt();
					 System.out.println("Enter Second No. :  ");
					 n=myObj.nextInt();
					 result=myAdd(m,n);
					 break;
				case 2 : System.out.println("Enter First No. :  ");
					 m=myObj.nextInt();
					 System.out.println("Enter Second No. :  ");
					 n=myObj.nextInt();
					 result=mySub(m,n);
					 break;	
				case 3 : System.out.println("Enter First No. :  ");
					 m=myObj.nextInt();
					 System.out.println("Enter Second No. :  ");
					 n=myObj.nextInt();
					 result=myMul(m,n);
					 break;
				case 4 : System.out.println("Enter First No. :  ");
					 m=myObj.nextInt();
					 System.out.println("Enter Second No. :  ");
					 n=myObj.nextInt();
					 result=myDiv(m,n);
					 break;
				default :
					myCheck=false;
			}
			if(myCheck==true){
				System.out.println("The result is :  "+result+"\n");
			}
		}while(myCheck==true);
	}
}