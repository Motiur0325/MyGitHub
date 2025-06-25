class Fact_Recursion{
    public static int fact(int n){
        if(n==1||n==0){
            return 1;
        }
        else{
            return n*fact(n-1);
        }
    }
    public static void main(String[]args){
        int n=6;
        System.out.println("Factorial of "+n+" : "+fact(n));    
    }
}