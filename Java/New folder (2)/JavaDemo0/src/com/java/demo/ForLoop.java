package com.java.demo;

public class ForLoop {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i;
		for(i=0;i<5;i++) {
			System.out.println(i);
		}
		for(i=0;i<5;i++) {
			for(int j=0;j<=i;j++) {
				System.out.print("* ");
			}
			System.out.println();
		}
		int arr[]= {11,22,33,44,55};
		for(int j: arr) {
			System.out.println(j);
		}
		for(int m=0;m<5;m++) {
			for(int n=0;n<5;n++) {
				if(m==n) {
					System.out.print("  ");
				}
				else {
					System.out.print("* ");
				}
			}
			System.out.println();
		}
		//INFINITE LOOP IN JAVA
		/*for(;;) {
			System.out.println("Infinite Loop.");
		}*/
	}

}
