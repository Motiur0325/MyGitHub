 #include <stdio.h>  
struct test {  
    int x;  
    char arr[8];  
    char arr1[10];
	char y;  
} u;  
int main()  
{  
	int arr[50];
	printf("%d\n",sizeof(arr));
    printf("%d", sizeof(u));  
    return 0;  
}  