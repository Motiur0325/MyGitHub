class Animal{
	public void animalSound(){
		System.out.println("The animal makes a sound!");
	}
}
class Cat extends Animal{
	public void animalSound(){
		System.out.println("The Cat says : meow! meow!");
	}
}
class Dog extends Animal{
	public void animalSound(){
		System.out.println("The Dog says : Bow! Wow!");
	}
}
class Sound{
	public static void main(String[] args){
	Animal myAnimal=new Animal();
	Animal myCat=new Cat();
	Animal myDog=new Dog();
	myAnimal.animalSound();
	myCat.animalSound();
	myDog.animalSound();
	}
}