public class Loop{
	public static void main(String[] args){
		String[] cars={"Bugatti","Lamborghini","Lexus","Lancia","Bentley","0"};
		int i=0;
		do{
			System.out.println(++i);
		}while(i<5);
		for(int j=1;j<=16;j=2*j){
			System.out.println(j);
		}
		for(String k : cars){
			if(k.indexOf("B")==0){
				System.out.println(k);
			}else{
				continue;
			}
		}
		System.out.println(cars[1]);
		System.out.println("The length of array is "+cars.length);
		cars[5]="Koenigsegg";		
		for(String z : cars){
			System.out.println(z);
		}
	}
}