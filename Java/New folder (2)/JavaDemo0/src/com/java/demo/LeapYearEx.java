package com.java.demo;

public class LeapYearEx {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int year=1900;
		String myStr="Hello";
		System.out.println(myStr);
		if(((year%400==0)&&(year%100!=0))||(year%4==0)) {
			System.out.println("Leap Year.");
		}
		else {
			System.out.println("Common Year.");
		}
	}

}
