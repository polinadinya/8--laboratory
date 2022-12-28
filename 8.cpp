#include <iostream>
#include <windows.h>
#include <time.h>
#include <queue>

void BFS(int v, int** G, int n)
{
	int* num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
	}
	std::queue <int> q;
	num[v] = 0;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		printf("%d ", v);
		for (int i = 0; i < n; i++)
		{
			if (G[v][i] == 1 && num[i] == 0)
			{
				q.push(i);
				num[i] = num[v] + 1;
			}
		}
	}
	printf("\n");
	printf("Расстояние до вершин:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
}


int main(void)
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, v;
	printf("Введите количество вершин графа: ");
	scanf_s("%d", &n);
	printf("Матрица смежности:\n");
	int** G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			if (i == j)
			{
				G[i][j] = 0;
			}
			G[j][i] = G[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", G[i][j]);
		}
		printf("\n");
	}
	printf("\nВершина, с которой начнется обход: ");
	scanf_s("%d", &v);
	BFS(v, G, n);
	printf("\n");
}
