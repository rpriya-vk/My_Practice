
#include <stdio.h>

int main(){
	int n, q;
	scanf("%d %d", &n, &q);              			
	//printf("Input number is %d.\n", num);       

	int *arr, query, l, r, i, j, index, range;
	arr = malloc(n *(sizeof(int *)));
	for(i = 0; i < n; i++){
	    scanf("%d", &arr[i]);
	}
	while(q--){
	    scanf("%d", &query);
        if(query == 1){
            //1X
	        scanf("%d", &index);
	        if(arr[index-1] == 0)
	            arr[index-1] = 1;
	        else
	            arr[index-1] = 0;
        }
        else{
            //0LR
            scanf("%d %d", &l, &r);
            /*int base = 1, deci_num = 0;
            for(i = arr[r-1]; i >= 0; i--){
                deci_num = deci_num + arr[r-1] * base;
                base = base * 2;
            }
            if((deci_num % 2) == 0)
                printf("EVEN");
            else
                printf("ODD");
            */
            if(arr[r-1] == 0)
                printf("EVEN\n");
            else
                printf("ODD\n");
	    }
    }
 }
