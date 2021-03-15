//#include <stdio.h>
//#define R 3
//
//int b[R];
//int cnt = 0;
//
//void PrintB() {
//	int i;
//
//	cnt++;
//	for (i = 0; i < R; i++) printf("%3d", b[i]);
//	printf("\n");
//}
//
//void exchange(int* p1, int* p2) {
//	int temp = *p1;
//
//	*p1 = *p2;
//	*p2 = temp;
//}
//
//void Permutation(int a[], int n, int r) {
//	int i;
//
//	if (r == R)PrintB();
//	else for (i = r; i <= n; i++) {
//		exchange(a + r, a + i);
//		b[r] = a[r];
//		Permutation(a, n, r + 1);
//		exchange(a + r, a + i);
//	}
//}
//
//int main(void) {
//	int a[] = { 1, 2, 3, 4, 5 };
//	int n = sizeof(a) / sizeof(int);
//
//	Permutation(a, n - 1, 0);
//	printf("순열 개수 : %d\n", cnt);
//
//	return 0;
//}