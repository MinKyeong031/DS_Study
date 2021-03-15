//#include <stdio.h>
//
//void InsertionSort(int a[], int n) {
//	int i, j, key;
//	for (i = 1; i < n; i++) {
//		key = a[i];
//		for (j = i - 1; j >= 0; j--) {
//			if (key >= a[j]) {
//				break;
//			}
//			else {
//				a[j + 1] = a[j];
//			}
//		}
//		a[j + 1] = key;
//	}
//}
//
//int main(void) {
//	int a[] = { 7, 12, 4, 11, 19, 23, 15, 28 };
//	int n;
//	n = sizeof(a) / sizeof(int);
//
//	InsertionSort(a, n);
//	printf("»ðÀÔ Á¤·Ä : ");
//	for (int i = 0; i < n; i++) {
//		printf("%5d", a[i]);
//	}
//	printf("\n");
//	return 0;
//}