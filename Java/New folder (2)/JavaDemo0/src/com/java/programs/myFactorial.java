package com.java.programs;

public class myFactorial {
	static int myFact(int n) {
		if(n==1||n==0)
			return 1;
		else {
			return(n*myFact(n-1));
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=6;
		System.out.println("Factorial of "+n+" is "+myFact(n));
	}

}
