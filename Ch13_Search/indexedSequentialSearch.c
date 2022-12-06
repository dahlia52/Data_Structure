// 색인 순차 탐색
#include <stdio.h>
#define MAX_SIZE 1000 // 주자료 테이블의 크기
#define INDEX_SIZE 10 // 인덱스 테이블의 크기

int list[MAX_SIZE] = {3, 9, 15, 22, 31, 55, 67, 88, 91}; // 주자료 테이블
int n = 9;

typedef struct{
    int key;
    int index;
} itable; // 인덱스 테이블 구조

itable index_list[INDEX_SIZE] = {{3,0}, {22,3}, {67,6}}; // 인덱스 테이블


int seq_search(int key, int low, int high) // 순차 탐색 함수
{
    int i;
    
     for (i=low; i<=high; i++)
        if (list[i] == key)
            return i;
    return -1;
}

// INDEX_SIZE는 인덱스 테이블의 크기, n은 전체 데이터수
int index_search(int key){
    int i, low, high;
    
    // 키 값이 리스트 범위 내의 값이 아니면 탐색 종료
    if (key < list[0] || key > list[n-1])
        return -1;
        
    // 인덱스 테이블을 조사하여 해당키의 구간 결정
    for (i=0; i<INDEX_SIZE; i++)
        if (index_list[i].key <= key && key < index_list[i+1].key)
            break;
    
    if (i == INDEX_SIZE){ // 인덱스 테이블의 끝이면
        low = index_list[i-1].index;
        high = n;
    }
    else{
        low = index_list[i].index;
        high = index_list[i+1].index;
    }
    // 예상되는 범위만 순차 탐색
    return seq_search(key, low, high);
}

int main()
{
    int i;
    i = index_search(67);
    if (i>=0)
        printf("탐색 성공 i = %d\n",i);
    else
        printf("탐색 실패\n");
}
