#include <stdio.h>
#include <stdlib.h>
#include "adjMatrix.h"
#define _CRT_SECURE_NO_WARNINGS

void createGraph(graphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			g->adjMatrix[i][j] = 0;
		}
	}
}
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	if (v < (g->n)) return;

	g->n++;
}

void insertEdge(graphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("\n그래프에 없는 정점입니다!");
		return;
	}
	g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(graphType* g) {
	int i, j;
	for (i = 0; i < (g->n); i++) {
		printf("\n\t\t");
		for (j = 0; j < (g->n); j++) {
			printf("%2d", g->adjMatrix[i][j]);
		}

	}
}

////////////////////////////////////////////////////////

void createGraph2(graphType2* g2) {
	int v2;
	g2->n2 = 0;
	for (v2 = 0; v2 < MAX_VERTEX2; v2++) {
		g2->adjList_H2[v2] = NULL;
	}
}
void insertVertex2(graphType2* g2, int v2) {
	if (((g2->n2) + 1) > MAX_VERTEX2) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g2->n2++;
}

void insertEdge2(graphType2* g2, int u2, int v2) {
	graphNode2* node2;
	if (u2 >= g2->n2 || v2 >= g2->n2) {
		printf("\n그래프에 없는 정점입니다!");
		return;
	}
	node2 = (graphNode2*)malloc(sizeof(graphNode2));


	node2->vertex2 = v2;
	node2->link2 = g2->adjList_H2[u2];
	g2->adjList_H2[u2] = node2;

}

void print_adjList2(graphType2* g2) {
	int i2;
	graphNode2* p2;
	for (i2 = 0; i2 < (g2->n2); i2++) {
		printf("\n\t\t정점%c의 인접 리스트", i2 + 65);
		p2 = g2->adjList_H2[i2];
		while (p2) {
			printf(" -> %c", p2->vertex2 + 65);
			p2 = p2->link2;
		}
	}
}