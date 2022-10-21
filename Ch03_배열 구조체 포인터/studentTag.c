#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct studentTag {
	char name[10];
	int age;
	double gpa;
};
void main() {
	struct studentTag s1;
	strcpy(s1.name, "kim");
	s1.age = 20;
	s1.gpa = 4.3;
	printf("%s, %d, %.2f", s1.name, s1.age, s1.gpa);
}