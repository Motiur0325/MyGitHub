package com.java.programs;

import java.lang.Math;
public class myArmstrong {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=153,i,count=0,sum=0;
		int temp=n;
		while(temp>0) {
			temp=temp/10;
			count++;
		}
		temp=n;
		for(i=1;i<=count;i++) {
			int r=n%10;
			sum+=(int)Math.pow(r,count);
			n=n/10;
		}
		if(sum==temp) {
			System.out.println("Armstrong Number");
		}
		else {
			System.out.println("Not a Armstrong Number");
		}
		int m=999;
		System.out.print("Armstrong Number upto "+m+" :  ");
		for(i=0;i<=m;i++) {
			temp=i;
			sum=0;
			count=0;
			while(temp>0) {
				temp=temp/10;
				count++;
			}
			temp=i;
			for(int j=1;j<=count;j++) {
				int r=temp%10;
				sum+=(int)Math.pow(r,count);
				temp=temp/10;
			}
			if(sum==i) {
				System.out.print(" "+i);
			}
		}
	}
}
