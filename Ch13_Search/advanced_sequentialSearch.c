// 순차 탐색
#include <stdio.h>

int seq_search(int list[], int key, int low, int high){
    for (int i=low; i<=high; i++)
        if (list[i] == key) 
            return i;   // 탐색 성공, 키 값의 인덱스 반환
    return -1; // 탐색 실패, -1 반환
}


int main(){
    int list[] = {3,6,2,6,2,3,9,7,1,5};
    
    int indx = seq_search(list, 9, 0, sizeof(list)-1);
    printf("%d",indx);
}
