#include<stdio.h>
void main(){
	char line[20],ctr;
	int i,c,end=0,w=0,lines=0,ch=0,sp=0;
	printf("Press Enter once to end lines\nPress Enter twice to end the paragraph.\n");
	printf("Enter the paragraph :\n\n");
	while(end==0){
		c=0;
		while((ctr=getchar())!='\n')
			line[c++]=ctr;
		line[c]='\0';
		if(line[0]=='\0')
			break;
		else{
			w++;
			for(i=0;line[i]!='\0';i++){
				if(line[i]==' '||line[i]=='\t')
					w++;
				if(line[i]==' '||line[i]=='\t')
					sp++;
			}
			lines+=1;
			ch=ch+strlen(line);
		}
	}
	printf("\n\nNo. of lines : %d\n",lines);
	printf("No. of words : %d\n",w);
	printf("No. of characters : %d",ch-sp);
	printf("\nNo. of spaces : %d",sp);
}