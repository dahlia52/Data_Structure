// 이진 탐색
#include <stdio.h>

int search_binary(int list[], int key, int low, int high)
{
    int middle;
    
    if (low <= high){
    middle = (low + high) /2;
    
    if (key == list[middle]) // 탐색 성공
        return middle;
    else if (key < list[middle]) // 왼쪽 부분 리스트 탐색
        search_binary(list, key, low, middle-1);
    else                        // 오른쪽 부분 리스트 탐색
        search_binary(list, key, middle+1, high);
    }
    return -1;
}

int main()
{
    int list[7] = {1,3,5,6,8,9,11};
    int n = sizeof(list)/sizeof(int);
    int idx = search_binary(list, 6, 0, n-1);
    printf("%d ", idx);
}
