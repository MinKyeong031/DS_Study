#include <stdio.h>
#define SIZE 6

int rear = -1, front = 0;
int cqueue[SIZE];
int cnt = 0;

int ADD(int data) {
	if (cnt == SIZE) {
		printf("CQueue is Overflow!\n");
		return -1;
	}
	cqueue[++rear % SIZE] = data;
	cnt++;

	return 0;
}

int DELETE(void) {
	if (cnt == 0) {
		printf("CQueue is Underflow!\n");
		return -1;
	}
	cnt--;

	return cqueue[front++ % SIZE];
}

int main(void) {
	ADD(10); ADD(20); ADD(30);
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());

	ADD(40); ADD(50); ADD(60);
	ADD(70); ADD(80); ADD(90);
	ADD(100);
	return 0;
}