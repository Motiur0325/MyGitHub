public class Main1{
	public void myDisplay(){
		System.out.println("Hello World");
	}
	static void myDisplay1(){
		System.out.println("Bye World");
	}
	public static void main(String[] args){
		Main1 myObj=new Main1();
		myDisplay1();
		myObj.myDisplay();
	}
}