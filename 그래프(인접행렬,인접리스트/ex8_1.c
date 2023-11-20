#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"
#define _CRT_SECURE_NO_WARNINGS



void main() {
	int i;
	graphType* G1 = (graphType*)malloc(sizeof(graphType));


	createGraph(G1);
	for (i = 0; i < 4; i++) {
		insertVertex(G1, i);
	}
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);
	printf("\n인접 행렬");
	printf("\n\n G1의 인접 행렬");
	print_adjMatrix(G1);


	graphType2* G2 = (graphType2*)malloc(sizeof(graphType2));

	createGraph2(G2);
	int j;
	for (j = 0; j < 4; j++) {
		insertVertex2(G2, j);
	}

	insertEdge2(G2, 0, 3);
	insertEdge2(G2, 0, 1);
	insertEdge2(G2, 1, 3);
	insertEdge2(G2, 1, 2);
	insertEdge2(G2, 1, 0);
	insertEdge2(G2, 2, 3);
	insertEdge2(G2, 2, 1);
	insertEdge2(G2, 3, 2);
	insertEdge2(G2, 3, 1);
	insertEdge2(G2, 3, 0);

	printf("\n G1의 인접 리스트");
	print_adjList2(G2);


}