#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int rear = -1, front = 0, cnt = 0;

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* cqueue[MAX];

int add(struct node* p) {
	if (cnt == MAX) {
		printf("Circular Queue is Full!\n");
		return -1;
	}
	cqueue[++rear % MAX] = p;
	cnt++;
	return 0;
}

struct node* get() { //queue에서 꺼내는 작업을 get()함수로 만듦
	struct node* value;
	if (cnt == 0) {
		return NULL;
	}
	value = cqueue[front];
	front = ++front % MAX;
	cnt--;
	return value;
}

struct node* create(char item) {
	struct node* p = (struct node*)malloc(sizeof(struct node));

	p->llink = NULL;
	p->data = item;
	p->rlink = NULL;
	return p;
}

void delete(struct node* p) {
	if (p != NULL) {
		delete(p->llink);
		delete(p->rlink);
		free(p);
	}
}

void dataPrint(char data) {
	static int first = 1;

	if (first == 1) {
		printf("%c", data);
		first = 0;
	}
	else printf(" -> %c", data);
}

void levelOrder(struct node* p) {
	dataPrint(p->data);
	if (p->llink != NULL) {
		dataPrint(p->llink->data);
		add(p->llink);
	}
	if (p->rlink != NULL) {
		dataPrint(p->rlink->data);
		add(p->rlink);
	}
	while ((p = get()) != NULL) {
		if (p->llink != NULL) {
			dataPrint(p->llink->data);
			add(p->llink);
		}
		if (p->rlink != NULL) {
			dataPrint(p->rlink->data);
			add(p->rlink);
		}
	}
}

int main(void) {
	struct node* root;

	root = create('A');
	root->llink = create('B');
	root->rlink = create('C');
	root->llink->llink = create('D');
	root->llink->rlink = create('E');
	root->rlink->llink = create('F');
	root->rlink->rlink = create('G');
	root->llink->rlink->llink = create('H');

	printf("Level Order 운행: ");
	levelOrder(root);

	printf("\n\n");

	delete(root);

	return 0;
}