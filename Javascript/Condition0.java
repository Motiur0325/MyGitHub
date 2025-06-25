import java.util.Scanner;

class Condition0{
	public static void main(String []args){
		int score;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter your score :  ");
		score=sc.nextInt();
		if(score<100){
			System.out.println("Beginner");
		}
		else if(score>100&&score<200){
			System.out.println("Pro");
		}
		else{
			System.out.println("Veteran");
		}			
	}
}