#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rec(int (x), int(y), int(wh), int(lh), int( **a)) {
	if (x >= wh || y >= lh || x<0 || y<0)
		return 0;
	if (a[x][y] == 0)
		return 0;
	if (a[x][y] == 2)
		return 0;
	if (x == wh-1 && y == lh-1)
		return 1;
	if (a[x][y] == 1) {
		a[x][y] = 2;
		return(rec(x + 1, y, wh, lh, a) + rec(x - 1, y, wh, lh, a)+ rec(x, y+1, wh, lh, a)+ rec(x, y-1, wh, lh, a));
	}

}

#define release

void main() {
	srand(time(NULL));
	int wh = 0, lh = 0, res = 0;
	printf("enter width and length of maze: ");
	scanf_s("%d %d", &wh, &lh);

	#ifdef debug
	printf("%d %d \n", wh, lh);
	#endif

	int** a = malloc(lh * sizeof(int));
	for (int i = 0; i < lh; i++) {
		a[i] = malloc(wh * sizeof(int));
	}

	for (int i = 0; i < lh; i++) {
		for (int j = 0; j < wh; j++) {
			a[i][j] = rand()%2;
		}
	}
	for (int i = 0; i < lh; i++) {
		for (int j = 0; j < wh; j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	res = rec(0, 0, wh, lh, a);

	#ifdef debug
	printf("%d", res);
	#endif

	if (res == 0)
		printf("No escape from the maze");
	else {
		printf("there are escape from the maze");
	}
}