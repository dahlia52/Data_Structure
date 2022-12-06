// 합병 정렬 

#include <stdio.h>
#define MAX_SIZE 100

int sorted[MAX_SIZE]; // 추가 공간이 필요

void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left; j=mid+1; k=left;
    
    // 분할 정렬된 list의 합병
    while (i<=mid && j<=right){
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i>mid)      // 남아 있는 레코드의 일괄 복사
        for (l=j; l<=right; l++)
            sorted[k++] = list[l];
    else            // 남아 있는 레코드의 일괄 복사
        for (l=i; l<=mid; l++)
            sorted[k++] = list[l];
    
    // 배열 sorted[]의 리스트를 배열 list[]로 복사
    for (l=left; l<=right; l++)
        list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right){
   int mid; 
   if (left < right){
       mid = (left + right)/2;          // 리스트의 균등 분할
       merge_sort(list, left, mid);     // 부분 리스트 정렬 (왼쪽)
       merge_sort(list, mid+1, right);  // 부분 리스트 정렬 (오른쪽)
       merge(list, left, mid, right); // 합병
   }
}
void print(int list[], int n){
    for (int i=0; i<n; i++)
        printf("%d ", list[i]);
}

int main()
{
   int n = 8;
   int list[] = {27,10,12,20,25,13,15,22};
   merge_sort(list, 0, n-1);
   print(list, n);
   return 0;
}