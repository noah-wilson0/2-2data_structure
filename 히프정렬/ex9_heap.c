#include <stdio.h>
#include "heap.h"
#define _CRT_SECURE_NO_WARNINGS


int main(void) {
	int i, n, item;
	heapType* heap = createHeap();
	inputHeap(heap);
/*
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);
*/
	printHeap(heap);
	n = heap->heap_size;
	
	int minHeap[5];
	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\ndelete: [%d] ", item);
		minHeap[n-i] = item;
		
	}
	printf("Array: ");
	for (int i = 0; i <5; i++) {
		printf("%4d ", minHeap[i]);
	}

	return 0;
}

