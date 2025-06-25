#include<stdio.h>
#include<stdlib.h>

struct employee{
	char name[30];
	int id;
	int salary;
}*emp;
typedef struct student{;
	char section;
	int percent;
	int age;
}stud;
void print_employee(int n){
	for(int i=0;i<n;i++){
		printf("EmployeeID :  %d\tEmployeeName :  %s\tEmployeeSalary :  %d\n",emp[i].id,emp[i].name,emp[i].salary);
	}
}
void main(){
//	int * arr;
//	for(int i=0;i<5;i++){
//		*(arr+i)=i;
//	}
//	for(int i=0;i<5;i++){
//		printf("%d ",*(arr+i));
//	}
	int n;
	printf("Enter the number of employee :  ");
	scanf("%d",&n);
	emp=(struct employee*)malloc(sizeof(struct employee)*n);
	for(int i=0;i<n;i++){
		printf("Enter employee name :  ");
		scanf("%s",&emp[i].name);
		emp[i].id=100+i+1;
		printf("Enter employee salary :  ");
		scanf("%d",&emp[i].salary);
	}
	print_employee(n);
	stud*stud1=(stud*)malloc(sizeof(stud));
	stud*stud2=(stud*)malloc(sizeof(stud));
//	stud*stud3=(stud*)malloc(sizeof(stud));
//	stud*stud4=(stud*)malloc(sizeof(stud));
	stud1->section='A';
	stud1->percent=89;
	stud1->age=17;
	stud2->section='B';
	stud2->percent=91;
	stud2->age=19;
	stud*stud_arr[2];
	stud_arr[0]=stud1;
	stud_arr[1]=stud2;
//	stud_arr[2]=stud3;
//	stud_arr[3]=stud4;
	printf("\n\n");
	for(int i=0;i<2;i++){
		printf("Section :  %c\tAge :  %d\tPercent :  %d\n",stud_arr[i]->section,stud_arr[i]->age,stud_arr[i]->percent);
	}
}