#include<stdio.h>

int front=-1,rear=-1;

void enque(int x[],int key){
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		x[rear]=key;
	}
	else{
		rear++;
		x[rear]=key;
	}
}
int deque(int x[]){
	int temp=x[front];
	x[front]='\0';
	if(front==rear&&rear!=-1){
		front=-1;
		rear=-1;
		return temp;
	}
	front++;
	return temp;
}
void print(int x[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void main(){
	int i,n,T=0,time=0;
	double avT=0,avW=0,avR=0;
	printf("Enter the number of processes :  ");
	scanf("%d",&n);
	int pro[n],arr[n],bur[n+1];
	int ready[n];
	int turn[n],wait[n],resp[n];
	for(i=0;i<n;i++){
		printf("\nEnter the arrival and burst time :  ");
		scanf("%d%d",&arr[i],&bur[i+1]);
		pro[i]=i;
		T+=bur[i+1];
	}	
	back:
		for(i=0;i<n;i++){
			if(arr[i]==time){
				enque(ready,pro[i]);
			}
		}
	bur[0]=0;
	while(time<T){
		int t=0;
		if(front!=rear||(front==rear&&rear!=-1)){
			//printf("Key[%d] :  %d",time,key);
			int key=deque(ready);
			while(t!=bur[key+1]){
				t++;
				time++;
				for(i=0;i<n;i++){
					if(arr[i]==time){
						enque(ready,pro[i]);
					}
				}
			}
			turn[key]=time-arr[key];
			avT+=turn[key];
			wait[key]=turn[key-1];
			avW+=wait[key];
			resp[key]=turn[key-1];
			avR+=resp[key];
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