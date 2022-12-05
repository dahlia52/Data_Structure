#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

void insertion_sort(int list[], int n){
    int i, j, key;
    for (i=1; i<n; i++){
        key = list[i]; // i 번째 숫자를 삽입하려고 함
        for (j=i-1; j>=0 && list[j]>key; j--)
            list[j+1] = list[j]; // 레코드의 오른쪽 이동
        list[j+1] = key;
    }
}

int main()
{
    int n, list[MAX_SIZE];
    n = MAX_SIZE;
    srand((unsigned)time(NULL));
    for (int i=0; i<n; i++) 
        list[i] = rand() % 100; // 0~99
        
    insertion_sort(list, n); 
    
    for (int i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}
