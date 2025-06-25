package com.java.demo;

public class ClassOpExaple {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a=10;
		int b=5;
		int c=20;
		//Java Logical and Bitwise Or
		System.out.println(a>b||++a<c);
		System.out.println(a);
		System.out.println(a>b|++a<c);
		System.out.println(a);
		//Java Ternary Operator
		System.out.println(a<b?a:b);
		//Short DataType Example
		short x=10;
		short y=10;
		x=(short)(x+y);
		System.out.println(x);
	}
}
