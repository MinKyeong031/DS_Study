#include <stdio.h>

int InterploationSearch(int a[], int n, int key){
	int left = 0, right = n - 1, mid;

	while (left <= right) {
		if (a[left] < a[right]) {
			mid = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
			if (mid < left) { mid = left; }
			if (mid > right) { mid = right; }
		}
		else {
			mid = left;
		}
		if (key == a[mid]) { return mid; }
		else if (key < a[mid]) { right = mid - 1; }
		else { left = mid + 1; }
	}
	return -1;
}

int main(void) {
	int a[] = { 7, 11, 14, 16, 20, 25, 27, 33, 38, 40, 47, 50 };
	int n, index, key;

	n = sizeof(a) / sizeof(int);

	printf("ã�� �� : ");
	scanf_s("%d", &key);

	index = InterploationSearch(a, n, key);

	if (index == -1) {
		printf("\nã���� �ϴ� Data ����!\n");
	}
	else {
		printf("\n%d ��ġ���� ã��!\n", index);
	}

	return 0;
}