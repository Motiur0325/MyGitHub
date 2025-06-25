package com.java.demo;

import java.util.Scanner;

public class VowelCheck {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try(Scanner myObj=new Scanner(System.in)){
		System.out.print("Enter the Character :  ");
		String myStr=myObj.next();
		System.out.println("CodeName :  "+ myStr);
		}
		char myChar='z';
		System.out.print("'" + myChar + "'" + " :  ");
		switch(myChar) {
			case 'A' :	System.out.println("Vowel");
						break;
			case 'a' :	System.out.println("Vowel");
						break;
			case 'E' :	System.out.println("Vowel");
						break;
			case 'e' :	System.out.println("Vowel");
						break;
			case 'I' :	System.out.println("Vowel");
						break;
			case 'i' :	System.out.println("Vowel");
						break;
			case 'O' :	System.out.println("Vowel");
						break;
			case 'o' :	System.out.println("Vowel");
						break;
			case 'U' :	System.out.println("Vowel");
						break;
			case 'u' :	System.out.println("Vowel");
						break;
			default :	System.out.println("Consonant");
		}
	}
}
