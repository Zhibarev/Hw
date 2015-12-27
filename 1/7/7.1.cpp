#include <cstdio>

using namespace std;

int const honestStudents = 3;

int fromWhomWriteOff(int currentStudent, int cheating[]) {
	if (cheating[currentStudent] > honestStudents)
		cheating[currentStudent] = fromWhomWriteOff(cheating[currentStudent], cheating);
	return cheating[currentStudent];
}

int main() {
	int numberOfStudents = 0;
	printf("Enter number of students\n");
	scanf("%d", &numberOfStudents);
	int *cheating = new int[numberOfStudents + 1];
	int currentStudent = 0;
	int StudentFromWhomWriteOff = 0;
	printf("Enter students and from whom they have written off (0 if student didn't pass)\n");
	for (int i = 1; i <= numberOfStudents - 3; i++) {
		scanf("%d %d", &currentStudent, &StudentFromWhomWriteOff);
		cheating[currentStudent] = StudentFromWhomWriteOff;
	}
	for (int i = 1; i <= 3; i++)
		cheating[i] = i;
	printf("Students and their version(0 if student didn't pass)\n");
	for (int i = 1; i <= numberOfStudents; i++) {
		fromWhomWriteOff(i, cheating);
		printf("%d %d\n", i, cheating[i]);
	}
	delete []cheating;
	return 0;
}