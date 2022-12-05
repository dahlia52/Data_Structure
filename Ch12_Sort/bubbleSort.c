#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void bubble_sort(int list[], int n){
    int i, j, temp;
    for (i=n-1; i>0; i--)
        for (j=0; j<i; j++)
            if (list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);
}

int main()
{
    int n, list[MAX_SIZE];
    n = MAX_SIZE;
    srand((unsigned)time(NULL));
    for (int i=0; i<n; i++) 
        list[i] = rand() % 100; // 0~99
        
    bubble_sort(list, n); 
    
    for (int i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}