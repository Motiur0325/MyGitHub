package com.java.demo;

public class DoWhile {
	//DO WHILE LOOP EXECUTES THE STATEMENT ONCE THEN CHECKS THE CONDITION FOR NEXT LOOP
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*int i=5;
		do {
			System.out.println(i);
			i--;
		}while(i>5);
		//WHILE LOOP CHECKS THE CONDITION FIRST AND THEN EXECUTES THE STATEMENT IF THE CONDITIONS ARE MET
		while(i>5) {
			System.out.println(i);
		}*/
		for(int m=1;m<4;m++) {
			bb:
			for(int n=1;n<4;n++) {
				if(m==n) {
					break bb;
				}
				System.out.print("* ");
			}
			System.out.println();
		}
		System.out.println("Hello");
	}
}
