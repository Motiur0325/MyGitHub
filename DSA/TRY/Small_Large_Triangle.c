#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void swap(int *a , int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    double area[n];
    for(int i=0;i<n;i++){
        double a=tr[i].a;
        double b=tr[i].b;
        double c=tr[i].c;
        double p=(a+b+c)/2;
        double root=p*(p-a)*(p-b)*(p-c);
        area[i]=sqrt(root);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(area[j]>=area[j+1]){
                double temp=area[j];
                area[j]=area[j+1];
                area[j+1]=temp;
                swap(&tr[j].a,&tr[j+1].a);
                swap(&tr[j].b,&tr[j+1].b);
                swap(&tr[j].c,&tr[j+1].c);
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}