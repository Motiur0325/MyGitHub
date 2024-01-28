public class Multi{
	public static void main(String[] args){
		int[][] myNum={{7,3,5,7,9},{0,2,4,6,8}};
		for(int i=0;i<myNum.length;i++){
			for(int j=0;j<myNum[i].length;j++){
				System.out.print(myNum[i][j]+" ");
			}
			System.out.println();
		}
	}
}