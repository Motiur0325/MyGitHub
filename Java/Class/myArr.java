import java.util.*;

public class myArr{
	public static void main(String[] args){
		ArrayList<String> myCars=new ArrayList<String>();
		myCars.add("Bugatti");
		myCars.add("Lamborghini");
		myCars.add("Audi");
		myCars.add("Koenigsegg");
		myCars.add("Lexus");
		Collections.sort(myCars);
		System.out.println(myCars);
		myCars.remove(2);
		myCars.set(3,"Ford");
		myCars.add("Porsche");
		Collections.sort(myCars);
		System.out.print(myCars);
		System.out.println("  :  "+myCars.size());
		myCars.clear();
		System.out.print(myCars);
		System.out.println("  :  "+myCars.size());
	}
}