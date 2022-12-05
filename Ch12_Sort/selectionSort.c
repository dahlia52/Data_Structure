#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>
#define MAX_SIZE 20

void selection_sort(int list[], int n){
    int least, temp;
    
    for (int i=0; i<n-1; i++){
        least = i;
        for (int j=i+1; j<n; j++) // 최소값의 위치 찾기
            if (list[least] > list[j])
                least = j;
                
        temp = list[i];
        list[i] = list[least];
        list[least] = temp;
    }
}

int main()
{
    int n, list[MAX_SIZE];
    n = MAX_SIZE;
    srand((unsigned)time(NULL));
    for (int i=0; i<n; i++) 
        list[i] = rand() % 100; // 0~99
        
    selection_sort(list, n); 
    
    for (int i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}
