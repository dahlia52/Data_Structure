// 구조체 배열
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;
void main() {
	student s[2] = { {"김이화", 20, 4.3}, {"최이화", 21,  3.7} };
	for (int i = 0; i < 2; i++)
		printf("%s, %d, %.2f \n", s[i].name, s[i].age, s[i].gpa);
}