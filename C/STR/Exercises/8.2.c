#include<stdio.h>
void main(){
	char name[30],ans[30]={"Dennis Ritchie"};
	int i=0,count=0;
	printf("%c\n",ans[6]);
	printf("Who is the inventor of C?\n");
	check:
		scanf("%s",&name);
	printf("\n");
	while(name[i]==ans[i]){
		printf("%c",name[i]);
		i++;
	}
	printf("\n%d\n",strcmp(name,ans));
	if(name[i]=='\0'&&ans[i]=='\0'){
		printf("\nGood");
	}
	else{
		printf("Try Again\n");
		count++;
		if(count<2)
			goto check;
		else
			exit(0);
	}
}