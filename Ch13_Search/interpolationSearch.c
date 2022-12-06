// 보간 탐색
#include <stdio.h>

int interpol_search(int list[], int key, int n){
    int low, high, j;
    
    low = 0;
    high = n-1;
    
    while ((list[high]>=key) && (list[low]<key)){
        j = ((int)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);
        
        if (key > list[j])
            low = j+1;
        else if (key < list[j])
            high = j-1;
        else
            low = j;
    }
    if (list[low] == key)
        return low;
    else    
        return -1;
}

int main()
{   
    int list[9] = {3, 9, 15, 22, 31, 55, 67, 88, 91};
    int idx = interpol_search(list, 55, 9);
    printf("%d",idx);
}
