#include <stdio.h>
#include "LinkedPoly.h";
#include <stdlib.h>;


ListNode* createLinkedList(void) {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}


void appendTerm(ListHead* L, float coef, int expo) {
	ListNode* newNode;
	ListNode* p;
	ListNode* prev = NULL;  // 이전 노드를 가리키는 포인터
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;
	/*
	 //초기 상태
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	else{
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNode;
	}
	*/
	
	p = L->head;
	// 차수가 높은 순서로 노드를 추가하기 위한 위치 탐색
	while (p != NULL && p->expo > expo) {
		prev = p;
		p = p->link;
	}

	// 차수가 같은 항이 이미 있을 경우 계수를 합함
	if (p != NULL && p->expo == expo) {
		p->coef += coef;
		free(newNode);  // 새로 생성한 노드는 필요 없으므로 메모리 해제
		return;
	}

	// newNode를 적절한 위치에 삽입
	newNode->link = p;
	if (prev == NULL) {  // 첫 번째 위치에 추가하는 경우
		L->head = newNode;
	}
	else {
		prev->link = newNode;
	}
	
}

void addPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;
	float sum;
	
	while (pA && pB) {
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			appendTerm(C, sum, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		else if (pA->expo > pB->expo) {
			appendTerm(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		else {
			appendTerm(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}
	for(; pA!=NULL;pA=pA->link)
		appendTerm(C, pA->coef, pA->expo);
	for (; pB != NULL; pB = pB->link)
		appendTerm(C, pB->coef, pB->expo);
}

void printPoly(ListHead* L) {
	ListNode* p = L->head;
	for (; p; p = p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL) printf(" +");
	}
}


