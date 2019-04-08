#include<stdio.h>
int main()
{
    int a[100001], N, value, Q, num,i,t;
    scanf("%d", &N);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d", &value);
        a[value]++;
    }
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d", &num);
        if(a[num] > 0)
            printf("%d\n", a[num]);
        else
            printf("NOT PRESENT\n");
    }
    return 0;
}
