#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Graph[1001][1001] = { 0 };
int DFSvisit[1001] = { 0 };
int BFSvisit[1001] = { 0 };
int queue[1001];
int cnt = 0;
/*void DFS(int v, int N) .//DFS로 풀어봤다.
{
	DFSvisit[v] = 1;
	for (int i = N; i > 1; i--)
	{
		if (Graph[v][i] == 1 && DFSvisit[i] == 0)
		{
			DFS(i, N);
			cnt++;
		}
	}
	
	
}*/

int BFS(int v, int N)
{
	int front = 0; int rear = 0; int pop, i,j=0;
	queue[0] = v;
	rear++;
	BFSvisit[v] = 1;
	while (front < rear)
	{
		pop = queue[front];
		front++;
		for (int i = 1; i <= N; i++)
		{
			if (Graph[pop][i] == 1 && BFSvisit[i] == 0)
			{
				queue[rear] = i;
				rear++;
				BFSvisit[i] = 1;
				j++;
				
			}
		}
	}
	return j;
}
int main()
{
	int N, M, START=1;
	int result = 0;

	scanf("%d" ,&N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}
	result=BFS(START, N);
	if (M == 0)
	{
		result = 0;//하나도 연결되어있지 않은 경우도 고려해준다.
	}
	
	printf("%d", result);
}