#include <stdio.h>
#define SIZE 6

int queue[SIZE] = { 0, }, front = 0, rear = -1;

int ADD(int data) {
	if (rear == SIZE - 1) {
		printf("Queue is Overflow!\n");
		return -1;
	}
	queue[++rear] = data;
	return 0;
}

int DELETE(void) {
	if (rear < front) {
		printf("Queue is Underflow!\n");
		return -1;
	}
	return queue[front++];
}

int main(void) {
	ADD(10); ADD(20); ADD(30);
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());

	ADD(40); ADD(50); ADD(60);
	ADD(70);
	return 0;
}