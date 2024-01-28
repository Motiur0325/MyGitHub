class Parent{
	protected int age=17;
	public void honk(){
		System.out.println("Don\'t Know");
	}
}
class Child extends Parent{
	private String Name="Uzumaki Naruto";
	public static void main(String[] args){
		Child myObj=new Child();
		System.out.println(myObj.Name+" is "+myObj.age+" years old");
		myObj.honk();
	}
}