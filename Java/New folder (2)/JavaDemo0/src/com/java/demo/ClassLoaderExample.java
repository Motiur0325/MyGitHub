package com.java.demo;

public class ClassLoaderExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Class c=ClassLoaderExample.class;
		System.out.println(c.getClassLoader());
		System.out.println(String.class.getClassLoader());
	}
} 
