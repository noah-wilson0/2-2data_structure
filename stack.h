#pragma once
#define STACK_SIZE 100

int stack[STACK_SIZE];

int isStackEmpty(void);
int isStackFull(void);
void push(int item);
int pop(void);
void printStack(void);