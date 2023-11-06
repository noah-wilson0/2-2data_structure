#include <stdio.h>
#include "stack.h";
#define _CRT_SECURE_NO_WARNINGS
int top = -1;

//������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty(void) {
	if (top == -1) return 1;
	else return 0;
}
//������ ��ȭ �������� Ȯ���ϴ� ����
int isStackFull(void) {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}
void push(int item) {
	if (isStackFull()) {
		printf("\n\n Stack is FULL! \n"); //isStackEmpty�� 1�϶� �����-> ������ ��ȭ����
		return;
	}
	else stack[++top] = item; // top�� ������Ų �� ����  top�� ���� ����
}
int pop(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty!!\n"); //������ ���� ������ ���
		return 0;
	}
	else return stack[top--]; // ����   top�� ���Ҹ� ������ ��  top����

}
void printStack(void) {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf(" ]");
}

int main(void) {
	int item, i;
	int element; //stack ���� �Է¹޴� ����
	printf("\n** ���� ���� ���� **\n");
	printStack();
	printf("\n");

	//������� �Է��� �޾Ƽ�  stack�� push�ϱ�
	for (i = 0; i < 5; i++) {
		printf("������ ���� �Է�:");
		scanf_s("%d", &element);
		push(element);
	}
	printStack(); //stack ���
	printf("\n\n");
	printf("top = %d\n", top);

	for (i = 0; i < 6; i++) {
		item = pop();
		printStack(); //stack ���
		printf("\t pop => %d\n", item);
	}
	//else return stack[top--]; ��  stack�迭 �ε����� ���ҽ��� ��ȯ �һ� 
	//������ �޸𸮻��� ���ҵ��� �����ϴ°� �ƴϴ�.
	printf("\n=====\n");
	printf("stack[4]==%d\n", stack[4]);

	return 0;
}