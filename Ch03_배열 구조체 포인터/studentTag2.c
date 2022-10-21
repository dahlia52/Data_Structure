# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;

void main() {
	student s1 = { "김이화", 20, 4.3 };
	student s2 = { "최이화", 21, 3.7 };
	
	printf("%s, %d, %.2f \n", s1.name, s1.age, s1.gpa);
	printf("%s, %d, %.2f \n", s2.name, s2.age, s2.gpa);
}