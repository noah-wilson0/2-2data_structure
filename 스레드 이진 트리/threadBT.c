//후속자 스레드만 갖고 있는 스레드 이진트리
#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"


treeThNode* makeRootThNode(char data, struct treeThNode* leftNode, struct treeThNode* rightNode, int isThreadRight) {
	treeThNode* root = (treeThNode*)malloc(sizeof(treeThNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;
	return root;
}

treeThNode* findThreadSuccessor(treeThNode* p) {
	treeThNode* q = p->right;
	if (q == NULL) return q;
	if (p->isThreadRight == 1) return q;
	while (q->left != NULL) q = q->left;
	return q;
}
void threadInorder(treeThNode* root) {
	treeThNode* q;
	q = root;
	while(q->left)  q = q->left; //애초에 여기서  왼쪽 서브트리의 가장 왼쪽으로 가는데 
	//n4->right = n5;
	//n5->right = n3;
	//n6->right = n7;
	//이걸 해도 AB/D 출력됨

	do {
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);
}