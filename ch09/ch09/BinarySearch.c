#include <stdio.h>

int BinarySearch(int a[], int n) {
	int left, right, mid, key;
	left = 0; right = n - 1;
	printf("찾을 값 : ");
	scanf_s("%d", &key);
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

int main(void) {
	int a[] = { 5, 7, 9, 14, 20, 24, 34, 56, 67, 89 };
	int n = sizeof(a) / sizeof(int);
	int index;
	index = BinarySearch(a, n);
	if (index == -1) {
		printf("찾고자하는 Data 없음!");
	}
	else {
		printf("%d에서 찾음!\n", index);
	}
	return 0;
}