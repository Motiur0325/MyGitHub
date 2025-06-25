class mainCar {
	public static void main(String[] args){
		car myObj=new car();
		car myObj1=new car();
		myObj1.name="Ford";
		myObj.setName("Ford");
		System.out.println(myObj1.name);
		System.out.println(myObj.getName());
	}
}