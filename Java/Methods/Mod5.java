public class Mod5{
	static int myAdd(int x){
		if(x>5){
			return x + myAdd(x-1);
		}
		else{
			return x;
		}
	}
	public static void main(String[] args){
		System.out.println(myAdd(10));
	}
}