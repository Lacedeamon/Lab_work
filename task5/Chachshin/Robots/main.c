#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define release

struct cell {
	int x;
	int y;
};
//����������� �������� ��� �����������, ���� �� ���� �� ����� (x,y) � (endx,endy) � �������� ������� ������������ ��� ����������� ������ ����
int rec(int(x), int(y), int endx, int endy, int(wh), int(lh), int(**a), int last) {
	if (x >= wh || y >= lh || x < 0 || y < 0)
		return 0;
	if (a[x][y] != 1)
		return 0;
	if (x == endx && y == endy) {
		a[x][y] = last;
		return 1;
	}
	if (a[x][y] == 1) {
		a[x][y] = last;
		return(rec(x + 1, y, endx, endy, wh, lh, a, last + 1) + rec(x - 1, y, endx, endy, wh, lh, a, last + 1) + rec(x, y + 1, endx, endy, wh, lh, a, last + 1) + rec(x, y - 1, endx, endy, wh, lh, a, last + 1));
	}
	return 0;
}
//������� ��� ����������� ������ ���� �� ����� (stx,sty) � ����� (endx,endy)
int pre_find_way(int wh, int lh, int stx, int sty, int endx, int endy, int(**a)) {

	int res = 0, x, y, fl = 0, n = 0, i = 0;

#ifdef debug
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
#endif

	res = rec(stx, sty, endx, endy, wh, lh, a, 2);

#ifdef debug
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
#endif;

	x = endx;
	y = endy;

	if (res == 0) {
		return(0);
	}
	else {
		while (x != stx || y != sty) {
			n = n + 1;
			fl = 0;
			if (x >= 1 && fl == 0) {
				if (a[x][y] - a[x - 1][y] == 1) {
					x = x - 1;
					y = y;
					fl = 1;
				}
			}
			if (x <= wh - 2 && fl == 0) {
				if (a[x][y] - a[x + 1][y] == 1) {
					x = x + 1;
					y = y;
					fl = 1;
				}
			}
			if (y >= 1 && fl == 0) {
				if (a[x][y] - a[x][y - 1] == 1) {
					x = x;
					y = y - 1;
					fl = 1;
				}
			}
			if (y <= lh - 2 && fl == 0) {
				if (a[x][y] - a[x][y + 1] == 1) {
					x = x;
					y = y + 1;
					fl = 1;
				}
			}
		}
		n = n + 1;
		return(n);
	}
}
//������� ��� ���������� ������� ��������, ���������� � main, ������ n, ����������� ��������� ���������� �������
int find_way(int wh, int lh, int stx, int sty, int endx, int endy, int(**a), struct cell *way) {

	int res = 0, x, y, fl = 0, n = 0, i = 0;
	res = rec(stx, sty, endx, endy, wh, lh, a, 2);
	x = endx;
	y = endy;

	if (res == 0) {
	}
	else {
		while (x != stx || y != sty) {
			struct cell pos = {x,y};
			way[i] = pos;
			i++;
			fl = 0;
			if (x >= 1 && fl == 0) {
				if (a[x][y] - a[x - 1][y] == 1) {
					x = x - 1;
					y = y;
					fl = 1;
				}
			}
			if (x <= wh - 2 && fl == 0) {
				if (a[x][y] - a[x + 1][y] == 1) {
					x = x + 1;
					y = y;
					fl = 1;
				}
			}
			if (y >= 1 && fl == 0) {
				if (a[x][y] - a[x][y - 1] == 1) {
					x = x;
					y = y - 1;
					fl = 1;
				}
			}
			if (y <= lh - 2 && fl == 0) {
				if (a[x][y] - a[x][y + 1] == 1) {
					x = x;
					y = y + 1;
					fl = 1;
				}
			}
		}
		struct cell pos = { x,y };
		way[i] = pos;
		return 0;
	}
	return 0;
}

void main() {
	
	srand(time(NULL));
	int wh = 0, lh = 0,n1,n2,i;
	
	printf("Enter width and length of maze ");
	scanf_s("%d %d", &wh, &lh);
	//�������� �������� � � �1
	int** a = malloc(wh * sizeof(int*));
	for (int i = 0; i < wh; i++) {
		a[i] = malloc(lh * sizeof(int));
	}
	int** a1 = malloc(wh * sizeof(int*));
	for (int i = 0; i < wh; i++) {
		a1[i] = malloc(lh * sizeof(int));
	}
	//���������� �������� � � �1 ����������� �������
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = rand() % 10;
			if (a[i][j] == 0) {
				a[i][j] = 0;
				a1[i][j] = 0;
			}
			else {
				a[i][j] = 1;
				a1[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	//����������� ������ ���� ��� 1 ������
	n1 = pre_find_way(wh, lh, 0, 0, wh - 1, lh - 1, a);
	//����������� ������� � � ����������� ���������
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j]=a1[i][j];
		}
	}
	//�������� ���������� ������� ���� ��� 1 ������
	struct cell *way = malloc(n1 * sizeof(struct cell));
	printf("%d \n",n1);
	//���������� 1 ���������� ������� ����
	i=find_way(wh, lh, 0, 0, wh - 1, lh - 1, a, way);
	//�������� ����������� �������
	struct cell* way1 = malloc(n1 * sizeof(struct cell));
	//���������� ����������� ������� ���� ������������ ��������� ��������
	for (int i = 0; i <n1; i++) {
		way1[n1 - i - 1] = way[i];
	}
	free (way);
#ifdef debug
	for (int i=0; i < n1; i++) {
		printf("(%d, %d)\n", way1[i].x, way1[i].y);
	}
#endif
	//����������� ������� � � ����������� ���������
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	//����������� ������ ���� ��� 2 ������
	n2= pre_find_way(wh, lh, 0, lh-1, wh - 1, lh - 1, a);
	//����������� ������� � � ����������� ���������
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	//�������� ���������� ������� ���� ��� 2 ������
	struct cell* wayy = malloc(n2 * sizeof(struct cell));
	printf("%d \n", n2);
	//���������� 2 ���������� ������� ����
	i = find_way(wh, lh, 0, lh-1, wh - 1, lh - 1, a, wayy);
	//�������� ����������� �������
	struct cell* way2 = malloc(n2 * sizeof(struct cell));
	//���������� ����������� ������� ���� ������������ ��������� ��������
	for (int i = 0; i < n2; i++) {
		way2[n2 - i - 1] = wayy[i];
	}
	free(wayy);
#ifdef debug
	for (int i = 0; i < n2; i++) {
		printf("(%d, %d)\n", way2[i].x, way2[i].y);
	}
#endif
	//����������� ������� � � ����������� ���������
	for (int i = 0; i < wh; i++) {
		for (int j = 0; j < lh; j++) {
			a[i][j] = a1[i][j];
		}
	}
	free(a);
	free(a1);
	for (int i = 0; i < n1 + n2; i++) {
		if (i < n1)
			printf("1 (%d,%d) \n\n", way1[i].x, way1[i].y);
		if (i < n2)
			printf("2 (%d,%d) \n\n", way2[i].x, way2[i].y);
	}
}
