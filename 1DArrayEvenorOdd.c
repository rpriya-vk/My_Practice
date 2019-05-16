/*Some problems appear hard though they are very easy. Today Aakash is stuck in a range query problem. He has been given an array with only numbers 0 and 1. There are two types of queries -

0 L R : Check whether the number formed from the array elements L to R is even or odd and print EVEN or ODD respectively. Number formation is the binary number from the bits status in the array L to R

1 X : Flip the Xth bit in the array

Indexing is 1 based

Input
First line contains a number N and Q as input. Next line contains N space separated 0 or 1. Next Q lines contain description of each query

Output
Output for only query type 0 L R whether the number in range L to R is "EVEN" or "ODD" (without quotes).

Constraints
1≤ N ≤ 10^6
1≤ L ≤ R ≤ 10^6
1≤ Q ≤ 10^6

1≤ X ≤ N



SAMPLE INPUT

5 2
1 0 1 1 0
1 2
0 1 4

SAMPLE OUTPUT

ODD

*/
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
