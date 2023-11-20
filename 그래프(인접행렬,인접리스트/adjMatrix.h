#pragma once
#define MAX_VERTEX 30
#define MAX_VERTEX2 30
typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];

}graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjMatrix(graphType* g);


typedef struct graphNode2 {
	int vertex2;
	struct graphNode2* link2;
}graphNode2;

typedef struct graphType2 {
	int n2;
	graphNode2* adjList_H2[MAX_VERTEX2];

}graphType2;

void createGraph2(graphType2* g2);
void insertVertex2(graphType2* g2, int v2);
void insertEdge2(graphType2* g2, int u2, int v2);
void print_adjList2(graphType2* g2);
