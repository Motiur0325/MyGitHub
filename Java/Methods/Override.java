public class Override{
	static int myAdd(int x,int y){
		return x+y;
	}
	static double myAdd(double x,double y){
		return x+y;
	}
	public static void main(String[] args){
		System.out.println(myAdd(43,32));
		System.out.println(myAdd(43.87,32.31));
	}
}