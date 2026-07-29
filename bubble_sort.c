#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int swapped = 0;
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
		}
		if (!swapped) break;
	}
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", arr[i]);
	}
	putchar('\n');
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) {
		fprintf(stderr, "Usage: provide N followed by N integers on stdin\n");
		return 1;
	}
	if (n <= 0) return 0;
	int *a = malloc(sizeof(int) * n);
	if (!a) {
		perror("malloc");
		return 1;
	}
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &a[i]) != 1) {
			fprintf(stderr, "Expected %d integers, got fewer\n", n);
			free(a);
			return 1;
		}
	}

	bubble_sort(a, n);
	print_array(a, n);

	free(a);
	return 0;
}