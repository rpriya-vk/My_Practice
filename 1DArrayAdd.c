#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              		
	
	int i = 0;
	int *a, *b, *c;
	a = malloc(num *(sizeof(int *)));
	b = malloc(num *(sizeof(int *)));
	c = malloc(num *(sizeof(int *)));
	for(i = 0; i < num; i++){
	    scanf("%d", &a[i]);
	}
	for(i = 0; i < num; i++){
	    scanf("%d", &b[i]);
	}
	for(i = 0; i < num; i++){
	    c[i] = a[i] + b[i];
	}	
	for(i = 0; i < num; i++){
	    printf("%d ", c[i]);
	}
}
