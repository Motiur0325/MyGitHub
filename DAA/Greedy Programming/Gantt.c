#include<stdio.h>

int front=-1,rear=-1,time=0;
int top=-1,count=0;

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
	//printf("\tRear :  %d,key : %d",rear,key);
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
		printf("%2d ",x[i]);
	}
	printf("\n");
}
void circ_print(int x[],int n){
	int i,front1=front;
	//printf("\nReady :  ");
	for(i=front1;i!=rear;i=(i+1)%n){
		printf("%d ",x[i]);
	}
	printf("%d\n",x[i]);
}
void stack(int n,int x[]){
	int a[4];
	int i=top;
	int t=time;
	if(top==-1){
		top++;
		a[top]=n;
		x[top]=t;
		//printf("\n\nA[0] :  %d",a[i]);
		return;
	}
	while(i>=0){
		if(a[i]==n){
			return;
		}
		//printf("%d[%d]-%d[%d] ",a[i],i,n,x[i]);
		i--;
	}
	if(top<4){
		top++;
		a[top]=n;
		x[top]=t;
	}
	count++;
}
void main(){
	int n=4,i,q=3,T=15;
//	printf("Enter the number of process :  ");
//	scanf("%d",&n);
	int pro[]={1,2,3,4};
	int arr[]={0,0,3,4};
	int ready[4];
	int rem[4]={3,4,4,4};
	int bur[4]={3,4,4,4};
	int turn[n],wait[4],resp[4];
	int CPU[4];
	/*for(i=0;i<n;i++){
		printf("Enter the Arrival and Burst Time for P[%d] :  ",i);
		scanf("%d%d",&arr[i],&bur[i]);
		T=T+bur[i];
		pro[i]=i+1;
	}
	printf("\nEnter the Quantum no :  ");
	scanf("%d",&q);*/
	printf("Process      :  ");
	print(pro,n);
	printf("Arrival Time :  ");
	print(arr,n);
	printf("Burst Time   :  ");
	print(bur,n);
	//printf("\nT : %d",T);
	back:
		for(i=0;i<n;i++){
			if(arr[i]==time){
				enque(ready,pro[i],n);
			}
		}
	while(time<T){
		int cyc=0,key;
		printf("\nReady at T[%d] : ",time);
		circ_print(ready,n);
		printf("Rear : %d  Front : %d\t",rear,front);
		if(rear!=front||(rear==front&&rear!=-1)){
			key=deque(ready,n);
			if(top<4){
				stack(key,CPU);
			}
			printf("\tKey : %d\n\n",key);
			while(cyc!=q){
				if(rem[key-1]==0){
					/*turn[key-1]=time-arr[key-1];
					wait[key-1]=turn[key-1]-bur[key-1];
					//printf("Key : %d  CPU : %d  arr :  %d\n",key,CPU[key-1],arr[key-1]);
					resp[key-1]=CPU[key-1]-arr[key-1];*/
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
				printf("Process        :  ");
				print(pro,n);
				printf("Remaining Time :  ");
				print(rem,n);
				printf("\n");
			}
			if(rem[key-1]==0){
				turn[key-1]=time-arr[key-1];
				wait[key-1]=turn[key-1]-bur[key-1];
				//printf("Key : %d  CPU : %d  arr :  %d\n",key,c,a);
				//printf("\nResp[%d] :  %d\n",key-1,resp[key-1]);
			}
			if(rem[key-1]!=0){
				enque(ready,key,n);
			}
		}
		else{
			time++;
			goto back;
		}
	}
	for(i=0;i<4;i++){
		resp[i]=CPU[i]-arr[i];
	}
	printf("Process         :  ");
	print(pro,n);
	printf("Turnaround Time :  ");
	print(turn,n);
	printf("Waiting Time    :  ");
	print(wait,n);
	printf("Response Time   :  ");
	print(CPU,n);
	printf("\nCount :  %d\n",count);
	print(resp,n);
}