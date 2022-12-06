// 이진 탐색 - 반복적인 버전
#include <stdio.h>

int search_binary2(int list[], int key, int low, int high)
{
    int middle;
    
     while(low <= high){            // 아직 숫자들이 남아 있으면
         middle = (low + high)/2;
         
         if (key == list[middle]) // 탐색 성공
            return middle;
        else if (key>list[middle])
            low = middle + 1; 
        else
            high = middle-1;
     }
     return -1;
}

int main()
{
    int list[7] = {1,3,5,6,8,9,11};
    int n = sizeof(list)/sizeof(int);
    int idx = search_binary2(list, 6, 0, n-1);
    printf("%d ", idx);
}
