// 셸 정렬 

#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

// gap만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;
    for (i=first+gap; i<=last; i=i+gap){
        key = list[i];
        for (j=i-gap; j>=first && list[j] > key; j = j-gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n){
    int i, gap;
    for (gap=n/2; gap>0; gap=gap/2){
        if ((gap%2)==0) gap++; // gap을 홀수로 만들어줌. (빠르다고 증명되어 있음)
        for (i=0; i<gap; i++) // 부분 리스트의 개수는 gap
            inc_insertion_sort(list, i, n-1, gap);
    }
}

int main()
{
    int n, list[MAX_SIZE];
    n = MAX_SIZE;
    srand((unsigned)time(NULL));
    for (int i=0; i<n; i++) 
        list[i] = rand() % 100; // 0~99
        
    shell_sort(list, n); 
    
    for (int i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}