#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void mergeSort(int a[], int m, int n);
int size;

int main(void) {
	int i,list[8] = { 69,10,30,2,16,8,31,22 };

	size = sizeof(list) / sizeof(list[0]);
	printf("\n정렬한 원소 >>");
	for (i = 0; i < size; i++) printf("%3d ", list[i]);

	printf("\n\n <<<<<<병합 정렬 수행>>>>>>\n");
	mergeSort(list, 0, size - 1);


	return 0;

}

