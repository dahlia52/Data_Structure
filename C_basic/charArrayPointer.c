# include <stdio.h>

int main() {
	char name1[] = "Kim, Ewha"; // ���� �迭
	char* name2 = "Kim, Ewha"; // ���ڿ� ����� �����ͷ� ����Ŵ

	printf("%s\n", name1); 
	printf("%s\n", name2);

	name1[2] = '0'; // ���� �迭 - ���� ����
	printf("%s\n", name1);
	name2[2] = 'X'; // ���ڿ� ��� - ���� �Ұ�
	printf("%s\n", name2);
}