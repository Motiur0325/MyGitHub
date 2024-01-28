public class Condition{
	public static void main(String[] args){
		int x=10,y=20;
		if(x>y){
			System.out.println(x+" is greater than "+y);
		}else if(Math.abs(x-y)==x){
			System.out.println("Number incremented.");
			x+=5;
		}else{
			System.out.println(x+" is lesser than "+y);
		}
		System.out.println(x);
		boolean result=(x>y)?false:true;
		System.out.println(result);
	}
}