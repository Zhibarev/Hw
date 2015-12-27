#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

void reverse(int min, int max, int array[]){
	for (int i = min; i <= (min - 1 + (max - min + 1) / 2); i++)
		swap(array[i], array[max + min - i]);
}
int main() {
	printf("Enter n,m\n");
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	printf("Enter array\n");
	int array[n + m + 1];
	for (int i = 1; i <= (n + m); i++)
		scanf("%d", &array[i]);
	reverse(1, n, array);
	reverse(n + 1, m + n, array);
	reverse(1, m + n, array);
	for (int i = 1; i <= (n + m); i++)
		printf("%d ", array[i]);
	return 0;
}