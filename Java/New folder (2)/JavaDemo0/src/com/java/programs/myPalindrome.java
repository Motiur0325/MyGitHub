package com.java.programs;
import java.util.*;
public class myPalindrome {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number : ");
		int n= sc.nextInt();
		int sum=0,r;
		int temp=n;
		while(n>0) {
			r=n%10;
			sum=(sum*10)+r;
			n=n/10;
		}
		if(temp==sum)
			System.out.println("Palindrome Number.");
		else
			System.out.println("Not a Palindrome Number");
	}

}
