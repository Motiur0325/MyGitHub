#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for(int i=0;i<2*n-1;i++){
        int k=0,m=n;
        for(int j=0;j<2*n-1;j++){
            if(i<n){
                if(k<i){
                    printf("%2d ",m);
                    m--;
                    k++;
                }
                else if(j>=(2*n-2-k)){
                    printf("%2d ",m);
                    m++;
                }
                else{
                    printf("%2d ",m);
                }
            }
            else{
                if(k<((2*n-2)-i)){
                    printf("%2d ",m);
                    m--;
                    k++;
                }
                else if(j>=(2*n-2-k)){
                    printf("%2d ",m);
                    m++;
                }
                else{
                    printf("%2d ",m);
                }
            }
        }
        printf("\n");
    }
    return 0;
}