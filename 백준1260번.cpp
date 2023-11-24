#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Graph[1001][1001] = { 0 };
int DFSvisit[1001] = { 0 };
int BFSvisit[1001] = { 0 };
int queue[1001];

void DFS(int v, int N)
{
	int i;
	DFSvisit[v] = 1;
	printf("%d ", v);
	for (i = 1; i <= N; i++)
	{
		if (Graph[v][i] == 1 && DFSvisit[i] == 0)
		{
			DFS(i, N);
		}
	}
	return;
}

void BFS(int v, int N)
{
	int front = 0, rear = 0, Pop, i;
	printf("%d ", v);
	queue[0] = v;

	rear++;;
	BFSvisit[v] = 1;
	while (front < rear)//내 생각엔 이게 BFS를 실행하면서 다음에 넘어갈지 말지를 정하는 것같아. 해당 NODE에 있는 모든걸 처리하는거지.
	{
		Pop = queue[front];//이것은 이중배열에서 1번째, 2번째 하면서 값들을 순서대로 집어넣는 동작이여
		front++;
		for (i = 1; i <= N; i++)
		{
			if (Graph[Pop][i] == 1 && BFSvisit[i] == 0)//
			{
				printf("%d ", i);
				queue[rear] = i;
				rear++;
				BFSvisit[i] = 1;

			}
		}
	}
	return;
}

int main()
{
	int N, M, Start;
	int i, x, y;
	scanf("%d%d%d", &N, &M, &Start);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;

	}
	DFS(Start, N);
	printf("\n");
	BFS(Start, N);
	return 0;
}