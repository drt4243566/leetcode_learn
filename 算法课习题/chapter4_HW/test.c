#include<stdio.h>

int main() {
	int a[5] = { 0 };
	int i;
	for (i = 1; i <= 10; i++) {
		a[i] = i;
	}
	for (i = 1 ; i <= 10; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
