public class Scope{
	public static void main(String[] args){
		int result=sum(7);
		System.out.println("Sum is : "+result);
	}
	static int sum(int x){
		if(x>0){
			return x*sum(x-1);
		}else if(x==1){
			return x;
		}else{
			return 1;
		}
	}
}