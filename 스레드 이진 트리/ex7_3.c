#include <stdint.h>
#include "threadBT.h"
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	
	treeThNode* n7 = makeRootThNode('D', NULL, NULL, 0);
	treeThNode* n6 = makeRootThNode('C', NULL, NULL, 1);
	treeThNode* n5 = makeRootThNode('B', NULL, NULL, 1);
	treeThNode* n4 = makeRootThNode('A', NULL, NULL, 1);
	treeThNode* n3 = makeRootThNode('/', n6, n7, 0);
	treeThNode* n2 = makeRootThNode('*', n4, n5, 0);
	treeThNode* n1 = makeRootThNode('-', n2, n3, 0);
	//중위 순회 //A  *  B  -  C  /   D 잘 나옴
	
	n4->right = n2;
	n5->right = n1;
	n6->right = n3;

	//전위 순회 -*AB/CD출력 되야하는데 AB/D 나옴
	/*
	n4->right = n5;
	n5->right = n3;
	n6->right = n7;
	*/

	printf("\n 스레드 이진 트리의 중위 순회:");
	threadInorder(n1);
	return 0;
}
