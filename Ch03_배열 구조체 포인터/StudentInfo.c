// 구조체 포인터의 활용
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
	student class[3] = { {"박이화", 90,90,90.0}, {"송이화", 100, 90, 95, 95.0}, {"Choi", 80, 90, 70, 80.0} };
	student* p1, * p2;

	p1 = &kim;
	p2 = &class;
	printf("%s의 국어 점수 =  %d, 영어 점수 = %d\n", p1->name, kim.english);
	printf("김이화의 이름의 첫 글자 = %c\n", p1[0].name[0]);
}