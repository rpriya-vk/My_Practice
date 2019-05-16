/*Microsoft has come to hire interns from your college. N students got shortlisted out of which few were males and a few females. All the students 
have been assigned talent levels. Smaller the talent level, lesser is your chance to be selected. Microsoft wants to create the result list 
where it wants the candidates sorted according to their talent levels, but there is a catch. This time Microsoft wants to hire female candidates 
first and then male candidates.

the task is to create a list where first all female candidates are sorted in a descending order and then male candidates are sorted in a descending order.

Input Format

The first line contains an integer N denoting the number of students. Next, N lines contain two space-separated integers, ai and bi.

The first integer,  ai will be either 1(for a male candidate) or 0(for female candidate).

The second integer, bi will be the candidate's talent level.

Constraints

1≤ N ≤ 10^5
0≤ ai ≤ 1
1≤ bi ≤ 10^9


Output Format

Output N space-separated integers, which first contains the talent levels of all female candidates sorted in descending order 
and then the talent levels of male candidates in descending order.


SAMPLE INPUT

5
0 3
1 6
0 2
0 7
1 15


SAMPLE OUTPUT

7 3 2 15 6

*/
#include <stdio.h>
#include <stdlib.h>

/*void simple_sort(int *arr, int arr_size)
{
    //Insertion Sort
    int i, j;
    int tmp;
    for (i = 0; i < arr_size; i++) {
        for (j = i + 1; j < arr_size; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}*/

int main() {
    int num_of_studs;
    int *arr;
    int f_idx, m_idx;
    int i, tmp, j;
    int fm, level;

    scanf("%d", &num_of_studs);
    if (num_of_studs <= 0) {
        goto err;
    }
    
    arr = malloc(sizeof(int *) * num_of_studs);
    if (!arr) {
        goto err;
    }

    f_idx = 0;
    m_idx = num_of_studs - 1;
    for (i = 0; i < num_of_studs; i++) {
        scanf("%d %d", &fm, &level);
        if (!fm) {
            /* If female */
            arr[f_idx] = level;
            if(f_idx > 0){
                for(j = 0; j < f_idx; j++){
                    if (arr[j] < arr[f_idx]) {
                        tmp = arr[j];
                        arr[j] = arr[f_idx];
                        arr[f_idx] = tmp;
                    }
                }
            }
            f_idx++;
        } else {
            /* If male */
            arr[m_idx] = level;
            if(m_idx < (num_of_studs-2)){
                for(j = num_of_studs-1; j > m_idx; j--){
                    if (arr[j] > arr[m_idx]) {
                        tmp = arr[j];
                        arr[j] = arr[m_idx];
                        arr[m_idx] = tmp;
                    }
                }
            }
            m_idx--;
        }
    }
    printf("Received %d female entries\n", f_idx);
    printf("Received %d male entries\n", (num_of_studs - 1) - m_idx);
    //simple_sort(arr, f_idx);
    //simple_sort(arr + m_idx + 1, (num_of_studs - 1) - m_idx);
    for (i = 0; i < num_of_studs; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
err:
    return -1;
}
