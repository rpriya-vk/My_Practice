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
