#include<stdlib.h>
#include<stdio.h>

void main(){
	system("dir");
	system("pause");
	if(system(NULL))
		printf("Command processor exist.");
	else
		printf("Command processor doesn't exist.'");
	system("C:\\Windows\\System32\\ipconfig");
	system("C:\\WINDOWS\\System32\\shutdown /s");
}