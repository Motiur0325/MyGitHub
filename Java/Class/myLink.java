import java.util.LinkedList;

public class myLink{
	public static void main(String[] args){
		LinkedList<String> names=new LinkedList<String>();
		names.add("Uzumaki Naruto");
		names.addLast("Uchiha Sasuke");
		names.addLast("Haruno Sakura");
		names.addFirst("Hatake Kakashi");
		names.addFirst("Jiraya");
		System.out.println(names);
		names.removeLast();
		System.out.println(names);
		System.out.println(names.getFirst());
		System.out.println(names.getLast());
	}
}