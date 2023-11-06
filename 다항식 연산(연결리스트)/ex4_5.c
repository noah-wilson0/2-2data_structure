#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LinkedPoly.h";


void main() {
	ListHead* A, * B, * C;
	int n, i;
	float s_coef;
	int s_expo;
	A = createLinkedList();
	B = createLinkedList();
	C = createLinkedList();
	/*
	//�ʱ����
	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	*/
	
	printf("A(x)�� ���� ���� �Է��ϼ���: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("�� #%d�� ����� ������ �Է��ϼ��� (��: 4 3): ", i + 1);
		scanf("%f %d", &s_coef, &s_expo);
		appendTerm(A, s_coef, s_expo);
	}

	printf("\n A(x)=");
	printPoly(A);

	/*
	//�ʱ� ����
	appendTerm(B, 3, 4);
	appendTerm(B, 1, 3);
	appendTerm(B, 2, 1);
	appendTerm(B, 1, 0);
	*/
	
	printf("\nB(x)�� ���� ���� �Է��ϼ���: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("�� #%d�� ����� ������ �Է��ϼ��� (��: 4 3): ", i + 1);
		scanf("%f %d", &s_coef, &s_expo);
		appendTerm(B, s_coef, s_expo);
	}

	printf("\n B(x)=");
	printPoly(B);

	addPoly(A, B, C);
	printf("\n C(x)=");
	printPoly(C);

	return 0;
}



