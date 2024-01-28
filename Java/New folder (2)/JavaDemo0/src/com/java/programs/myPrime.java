package com.java.programs;

public class myPrime {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=4,f=0;
		if(n==0||n==1) {
			System.out.println(n+" is not a prime number.");
			f=1;
		}
		for(int i=2;i<=n/2;i++) {
			if(n%i==0) {
				f=1;
				System.out.println(n+ " is not a prime number.");
				break;
			}
		}
		if(f==0) {
			System.out.println(n+" is a prime number.");
		}
	}

}
