import java.util.Scanner;

public class UserIp{
	public static void main(String[] args){
		Scanner myInput=new Scanner(System.in);
		System.out.println("Enter name, age and salary :- ");
		String name=myInput.nextLine();
		int age=myInput.nextInt();
		double salary=myInput.nextDouble();
		System.out.println(name+" is an employee of age "+age+" years with a salary of "+salary);
	}
}		