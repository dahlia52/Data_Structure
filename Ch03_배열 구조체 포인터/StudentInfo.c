// ����ü �������� Ȱ��
# include <stdio.h>

typedef struct StudentInfo {
	char name[10];
	int korean;
	int english;
	int math;
	double average;
}student;

int main() {
	student kim = { "kim, ewha", 100, 90, 95, 95.0 };
	student class[3] = { {"����ȭ", 90,90,90.0}, {"����ȭ", 100, 90, 95, 95.0}, {"Choi", 80, 90, 70, 80.0} };
	student* p1, * p2;

	p1 = &kim;
	p2 = &class;
	printf("%s�� ���� ���� =  %d, ���� ���� = %d\n", p1->name, kim.english);
	printf("����ȭ�� �̸��� ù ���� = %c\n", p1[0].name[0]);
}