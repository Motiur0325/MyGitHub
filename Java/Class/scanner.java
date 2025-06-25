package com.java.demo;

import java.util.Scanner;

class scanner{
	public static void main(String[] args){
		try(Scanner myObj=new Scanner(System.in)){
		System.out.print("Enter user name : ");
		String userName=myObj.next();
		System.out.println("User Name :  "+userName);
		}
	}
}