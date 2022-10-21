// 2차원 배열을 가리키는 배열에 대한 포인터
# include <stdio.h>

int main() {
	int A[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int(*p)[4] = A; // 배열에 대한 포인터 선언과 초기화

	printf("*** 배열 A\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			printf("%3d", A[i][j]);
		printf("\n");
	}

	printf("\n*** p가 가리키는 배열\n");
	for (int i = -0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			printf("%3d", p[i][j]);
		printf("\n");
	}
}