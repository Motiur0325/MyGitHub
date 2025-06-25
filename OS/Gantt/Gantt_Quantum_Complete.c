#include<stdio.h>

int front=-1,rear=-1,time=0;
int top=-1;

void enque(int x[],int key,int n){
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		x[rear]=key;
	}
	else{
		rear=(rear+1)%n;
		x[rear]=key;
	}
}
int deque(int x[],int n){
	int temp=x[front];
	x[front]='\0';
	if(front==rear&&front!=-1){
		front=-1;
		rear=-1;
		return temp;
	}
	front=(front+1)%n;
	return temp;
}
void print(int x[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void circ_print(int x[],int n){
	int i,front1=front;
	for(i=front1;i!=rear;i=(i+1)%n){
		printf("%d ",x[i]);
	}
	printf("%d\n",x[i]);
}
void stack(int n,int x[],int a[],int p){
	int i=top;
	int t=time;
	while(i>=0){
		if(a[i]==n){
			return;
		}
		i--;
	}
	if(top<p){
		top++;
		a[top]=n;
		x[top]=t;
	}
}
void main(){
	int n,i,q=3,T=15;
	double avT=0,avW=0,avR=0;
	printf("Enter the number of process :  ");
	scanf("%d",&n);
	int pro[n],arr[n],A[n];
	int ready[n],rem[n],bur[n];
	int turn[n],wait[n],resp[n];
	int CPU[n];
	for(i=0;i<n;i++){
		printf("Enter the Arrival and Burst Time for P[%d] :  ",i);
		scanf("%d%d",&arr[i],&bur[i]);
		T=T+bur[i];
		rem[i]=bur[i];
		pro[i]=i+1;
	}
	printf("\nEnter the Quantum no :  ");
	scanf("%d",&q);
	back:
		for(i=0;i<n;i++){
			if(arr[i]==time){
				enque(ready,pro[i],n);
			}
		}
	while(time<T){
		int cyc=0,key;
		if(rear!=front||(rear==front&&rear!=-1)){
			printf("\nReady :  ");
			circ_print(ready,n);
			key=deque(ready,n);
			if(top<4){
				stack(key,CPU,A,n);
			}
			while(cyc!=q){
				if(rem[key-1]==0){
					break;
				}
				else{
					rem[key-1]--;
					time++;
					cyc++;
					for(i=0;i<n;i++){
						if(arr[i]==time){
							enque(ready,pro[i],n);
						}
					}
				}
			}
			if(rem[key-1]==0){
				turn[key-1]=time-arr[key-1];
				avT=avT+turn[key-1];
				wait[key-1]=turn[key-1]-bur[key-1];
				avW=avW+wait[key-1];
				resp[key-1]=CPU[key-1]-arr[key-1];
				avR=avR+resp[key-1];
			}
			else{
				enque(ready,key,n);
			}
		}
		else{
			time++;
			goto back;
		}
	}
	printf("\nTurnaround Time :  ");
	print(turn,n);
	printf("Waiting Time :  ");
	print(wait,n);
	printf("Response Time :  ");
	print(resp,n);
	printf("\nAverage\n-----------\n1.Turnaround : %.2f\n2.Waiting : %.2f\n3.Response : %.2f\n",avT/n,avW/n,avR/n);
}