public class Str{
	public static void main(String[] args){
		String newTxt="Hello \"This\"\n is nothing\'";
		String myTxt="ABcDEFghiJKl";
		String fN="Who",lN="Knows";
		int a=3333;
		System.out.println("The length of string is : "+myTxt.length());
		System.out.println(myTxt);
		System.out.println(myTxt.toUpperCase());
		System.out.println(myTxt.toLowerCase());
		System.out.println(myTxt.indexOf("E"));
		System.out.println(fN+" "+lN);
		System.out.println(fN.concat(" "+lN));
		System.out.println(fN+a);
		System.out.println(newTxt);
	}
}