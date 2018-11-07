#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 110

struct node{
	int value;
	struct node* next;
};

struct node* CreateNode(int InputNode) {
	struct node* TempNode = (struct node*)malloc(sizeof(struct node));	
	TempNode->value = InputNode;
	TempNode->next = NULL;
	return TempNode;
};

struct node* HeadPointers[N + 10];
int ShortestPath[N + 10];
int ShortestPathIndex = 0;
int ExitNode;

bool dfs(int source) {
	if (source == ExitNode)
		return true;

	int TotalConnectionsForSource = 0;
	int i;
	int InputNode;
	struct node* CurrentNode;
	bool IsCurrentNodeIncluded;

	printf("Enter number of nodes connecting to %d\n", source);
	scanf("%d", &TotalConnectionsForSource);
	if (TotalConnectionsForSource == 0)
		return false;
	printf("Enter nodes\n");
	for (i = 0; i < TotalConnectionsForSource; i++) {
		scanf("%d", &InputNode);
		struct node* TempNode = CreateNode(InputNode);
		if (HeadPointers[source] == NULL) {
			HeadPointers[source] = TempNode;
			CurrentNode = TempNode;
		}
		else {
			CurrentNode->next = TempNode;
			CurrentNode = TempNode;
		}
	}

	CurrentNode = HeadPointers[source];
	while(CurrentNode != NULL) {
		IsCurrentNodeIncluded = dfs(CurrentNode->value);
		if (IsCurrentNodeIncluded == true) {
			ShortestPath[ShortestPathIndex] = source;
			ShortestPathIndex++;
			return true;
		}
		CurrentNode = CurrentNode->next;
	}
	return false;
}
int main() {
	// Intially, all pointer pointing to NULL
	int i;
	for (i = 0; i < N; i++)
		HeadPointers[i] = NULL;
	printf("Enter the exit node\n");
	scanf("%d", &ExitNode);
	bool IsCurrentNodeIncluded = dfs(0);
	printf("Shortest Path is :\n");
	printf("%d <-- ", ExitNode);
	for (i = 0; i < ShortestPathIndex; i++) {
		if (i == ShortestPathIndex - 1)
			printf("%d\n", ShortestPath[i]);
		else
			printf("%d <-- ", ShortestPath[i]);
	}
	return 0;
}