#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* CREATE(char item) {
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->llink = NULL;
	ptr->data = item;
	ptr->rlink = NULL;
	return ptr;
}

void PreOrder(struct node* p) {
	if (p != NULL) {
		printf("%c ", p->data);
		PreOrder(p->llink);
		PreOrder(p->rlink);
	}
}

void InOrder(struct node* p) {
	if (p != NULL) {
		InOrder(p->llink);
		printf("%c ", p->data);
		InOrder(p->rlink);
	}
}

void PostOrder(struct node* p) {
	if (p != NULL) {
		PostOrder(p->llink);
		PostOrder(p->rlink);
		printf("%c ", p->data);
	}
}

void deletenode(struct  node* p) {
	if (p != NULL) {
		deletenode(p->llink);
		deletenode(p->rlink);
		free(p);
	}
}

void main(void) {
	struct node* root;

	root = CREATE('A');
	root->llink = CREATE('B');
	root->rlink = CREATE('C');
	root->llink->llink = CREATE('D');
	root->llink->rlink = CREATE('E');
	root->rlink->llink = CREATE('F');
	root->rlink->rlink = CREATE('G');
	root->llink->rlink->llink = CREATE('H');

	PreOrder(root); printf("\n");
	InOrder(root); printf("\n");
	PostOrder(root); printf("\n");

	printf("사라지는 순서 : ");
	deletenode(root);

	return 0;
}