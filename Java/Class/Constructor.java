public class Constructor{
	int Age;
	String Name;
	public Constructor(int x,String N){
		Age=x;
		Name=N;
	}
	public static void main(String[] args){
		Constructor myObj=new Constructor(20,"Uchiha Sasuke");
		System.out.println(myObj.Name+" is "+myObj.Age+" years old.");
	}
}