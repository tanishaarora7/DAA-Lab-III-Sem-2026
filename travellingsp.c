practical 13
TRAVELLING SALESMAN PROBLEM
TANISHA ARORA 25070521116

#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int n;
int **matrix;
int **memo;

int min(int a, int b) {
	return (a < b) ? a : b;
}
int tsp(int mask, int curr) {
	if (mask == (1 << n) - 1) {
		return (matrix[curr][0] != -1) ? matrix[curr][0] : INF;
	}
	if (memo[mask][curr] != -1) {
		return memo[mask][curr];
	}
	int ans = INF;
	for (int nxt = 0; nxt < n; nxt++) {
		if (!(mask & (1 << nxt))) {
			if (matrix[curr][nxt] != -1) {
				ans = min(ans, matrix[curr][nxt] + tsp(mask | (1 << nxt), nxt));
			}
		}
	}
	return memo[mask][curr] = ans;
}

int main() {
	if (scanf("%d", &n) != 1) return 0;
	matrix = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		matrix[i] = (int *)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	int total_states = 1 << n;
	memo = (int **)malloc(total_states * sizeof(int *));
	for (int i = 0; i < total_states; i++) {
		memo[i] = (int *)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			memo[i][j] = -1;
		}
	}
	int result = tsp(1, 0);
	if (result >= INF) {
		printf("-1\n");
	} else {
		printf("%d\n", result);
	}
	for (int i = 0; i < total_states; i++) {
		free(memo[i]);
	}
	free(memo);
	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
