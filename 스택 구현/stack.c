#include <stdio.h>
#include "stack.h";
#define _CRT_SECURE_NO_WARNINGS
int top = -1;

//스택이 공백 상태인지 확인하는 연산
int isStackEmpty(void) {
	if (top == -1) return 1;
	else return 0;
}
//스택이 포화 상태인지 확인하는 연산
int isStackFull(void) {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}
void push(int item) {
	if (isStackFull()) {
		printf("\n\n Stack is FULL! \n"); //isStackEmpty이 1일때 실행됨-> 스택이 포화상태
		return;
	}
	else stack[++top] = item; // top을 증가시킨 후 현재  top에 원소 삽입
}
int pop(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty!!\n"); //스택이 공백 상태인 경우
		return 0;
	}
	else return stack[top--]; // 현재   top의 원소를 삭제한 후  top감소

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
	int element; //stack 원소 입력받는 변수
	printf("\n** 순차 스택 연산 **\n");
	printStack();
	printf("\n");

	//사용자의 입력을 받아서  stack에 push하기
	for (i = 0; i < 5; i++) {
		printf("삽일할 원소 입력:");
		scanf_s("%d", &element);
		push(element);
	}
	printStack(); //stack 출력
	printf("\n\n");
	printf("top = %d\n", top);

	for (i = 0; i < 6; i++) {
		item = pop();
		printStack(); //stack 출력
		printf("\t pop => %d\n", item);
	}
	//else return stack[top--]; 은  stack배열 인덱스를 감소시켜 반환 할뿐 
	//실제로 메모리상의 원소들을 삭제하는게 아니다.
	printf("\n=====\n");
	printf("stack[4]==%d\n", stack[4]);

	return 0;
}