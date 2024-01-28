#include<stdio.h>
#include<ctype.h>

int top=-1,top1=-1,head=-1;
char expr[30],symbol[30],postfix[30],sym[30];

void push(char x[],int *t,int y){
	*t=*t+1;
	x[*t]=y;
	if(x==symbol){
		head++;
		sym[head]=y;
	}
}
int pop(){
	if(top1==-1)
		return(-1);
	else
		return(symbol[top1--]);
}
int priority(char x){
	if(x=='(')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/')
		return 2;
	if(x=='^'||x=='%')
		return 3;
	return 0;
}
void display(char x[],int *t){
	int start;
	printf("Expression :  ");
	for(start=0;start<=*t;start++){
		printf("%c ",x[start]);
	}
	printf("\n\n");
}
int main(){
	int i=0,n=0;
	char *e,x;
	printf("Enter infix expression :  ");
	scanf("%s",&expr);
	printf("\n");
	e=expr;
	while(*e!='\0'){
		if(isalnum(*e))
			push(postfix,&top,*e);
		else if(*e=='('){
			push(symbol,&top1,*e);
		}
		else if(*e==')'){
			push(sym,&head,*e);
			while((x=pop(top1))!='('){
				push(postfix,&top,x);
			}
		}
		else{
			while(priority(*e)<=priority(symbol[top1])){
				push(postfix,&top,pop());
			}
			push(symbol,&top1,*e);
		}
		e++;
	}
	while(top1!=-1&&symbol[top1]!='('){
		push(postfix,&top,pop(top1));
	}
		printf("Infix Expression :  %s\n\nSymbolic ",expr);
		display(sym,&head);
		printf("Postfix ");
		display(postfix,&top);
}