#include <stdio.h>
#include <limits.h>
#define SIZE 9

int minVertex(int D[], int chk[]) {
	int i, minValue = INT_MAX, minIndex;

	for (i = 0; i < SIZE; i++)
		if (chk[i] == 0 && minValue > D[i]) {
			minValue = D[i];
			minIndex = i;
		}

	return minIndex;
}

void Dijkstra(int G[SIZE][SIZE], int D[], int P[], int i) {
	int chk[SIZE] = { 0, };
	int j, cnt = 0;

	for (j = 0; j < SIZE; j++)
		if (G[i][j] > 0 && G[i][j] < INT_MAX) {
			D[j] = G[i][j];
			P[j] = i;
		}
	chk[i] = 1;
	cnt++;

	printf("\n%d단계", cnt);
	printf("\n  D:");
	for (i = 0; i < SIZE; i++) {
		if (D[i] == INT_MAX) printf("  ∞");
		else printf("%4d", D[i]);
	}
	printf("\n  P:");
	for (i = 0; i < SIZE; i++)printf("%4d", P[i]);
	printf("\nchk:");
	for (i = 0; i < SIZE; i++)printf("%4d", chk[i]);
	printf("\n");

	while (cnt < SIZE) {
		i = minVertex(D, chk);
		for (j = 0; j < SIZE; j++)
			if (G[i][j] > 0 && G[i][j] < INT_MAX) //인접해 있고
				if (D[j] > D[i] + G[i][j]) { //axis를 거치는 경로가 짧다면
					D[j] = D[i] + G[i][j]; //짧은 거리로 업데이트
					P[j] = i; //axis를 거치도록 경로 설정
				}
		chk[i] = 1; //살펴 볼 축에서 제외
		cnt++;

		printf("\n%d단계", cnt);
		printf("\n  D:");
		for (i = 0; i < SIZE; i++) {
			if (D[i] == INT_MAX) printf("  ∞");
			else printf("%4d", D[i]);
		}
		printf("\n  P:");
		for (i = 0; i < SIZE; i++)printf("%4d", P[i]);
		printf("\nchk:");
		for (i = 0; i < SIZE; i++)printf("%4d", chk[i]);
		printf("\n");
	}
}

int main(void) {
	int G[SIZE][SIZE] = { {0, 16, 19, INT_MAX, 27,INT_MAX, INT_MAX, INT_MAX, INT_MAX},
						 {16, 0, 5, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
						 {19, INT_MAX, 0, INT_MAX, 10, INT_MAX, 22, INT_MAX, INT_MAX},
						 {INT_MAX, 5, INT_MAX, 0, 20, 30, INT_MAX, INT_MAX, INT_MAX},
						 {27, INT_MAX, 10, 20, 0, INT_MAX, 43, INT_MAX, INT_MAX},
						 {INT_MAX, INT_MAX, INT_MAX, 30, INT_MAX, 0, INT_MAX, 63, INT_MAX},
						 {INT_MAX, INT_MAX, 22, INT_MAX, 43, INT_MAX, 0, 5, 19},
						 {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 63, 5, 0, 31},
						 {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 19, 31, 0} };

	char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	char shortestPath[SIZE];
	char departureVertex, arrivalVertex;
	int P[SIZE] = { 0, };
	int D[SIZE] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX };
	int i, j, vertexNum, vertexCnt = 0, departureNum;

	printf("\n\t[인접 정점과의 거리]\n ");
	for (i = 0; i < SIZE; i++)printf("%4c", V[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++) {
		printf("%c", V[i]);
		for (j = 0; j < SIZE; j++)
			if (G[i][j] == INT_MAX)printf("%4c", '-');
			else printf("%4d", G[i][j]);
		printf("\n");
	}

	printf("\n출발 정점(A~H) : ");
	scanf_s("%c", &departureVertex, 1);
	getchar();
	printf("도착 정점(A~H) : ");
	scanf_s("%c", &arrivalVertex, 1);
	getchar();
	while (departureVertex == arrivalVertex) {
		printf("출발과 도착이 같습니다. 도착 정점(A~H) : ");
		scanf_s("%c", &arrivalVertex, 1);
		getchar();
	}

	for (i = 0; i < SIZE; i++) if (arrivalVertex == V[i]) break;
	D[i] = 0;
	P[i] = i;

	Dijkstra(G, D, P, i);

	printf("\n각 정점에서 도착 정점 %c까지 최단 경로 및 거리\n", arrivalVertex);

	for (i = 0; i < SIZE; i++) {
		if (V[i] == arrivalVertex) continue;
		printf("%c", V[i]);

		if (V[i] == departureVertex) departureNum = i;

		vertexNum = i;
		while (V[vertexNum] != arrivalVertex) {
			vertexNum = P[vertexNum];
			printf(" -> %c", V[vertexNum]);
			if (V[i] == departureVertex) shortestPath[vertexCnt++] = V[vertexNum];
		}
		printf(", %d\n", D[i]);
	}

	printf("\n출발 정점 %c에서 도착 정점 %c까지 최단 경로 및 거리 : ", departureVertex, arrivalVertex);
	printf("%c", departureVertex);
	for (i = 0; i < vertexCnt; i++)
		printf(" -> %c", shortestPath[i]);
	printf(", %d\n\n", D[departureNum]);

	return 0;
}