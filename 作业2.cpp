//Floyd
#include<stdio.h>
#include<stdlib.h>
int main() {
	int d[10][10], i, j, k, n, m, x, y, z;
	printf("输入顶点数和边数：\n");
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) {
				d[i][j] = 0;
			}
			else {
				d[i][j] = 10000;
			}
		}
	}
	printf("输入从？顶点到？顶点的距离？：");
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = z;
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d", d[i][j]);
			if (j != n) {
				printf(" ");
			}
			else {
				printf("\n");
			}
		}
	}
	return 0;
}


//Dijkstra
#include<stdio.h>
#include<stdlib.h>
int i, j, n, m, max = 10000, sum, x, y, z, k;
int a[100][100], d[100], p[100];
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
	}
	for (i = 1; i <= n; i++) {
		d[i] = max;
	}
	d[1] = 0;
	for (i = 1; i <= n; i++)
	{
		sum = max;
		for (j = 1; j <= n; j++) {
			if (!p[j] && d[j] < sum)
			{
				sum = d[j];
				k = j;
			}
		}
		p[k] = 1;
		for (j = 1; j <= n; j++) {
			if (a[k][j] != 0 && !p[j] && d[j] > d[k] + a[k][j])
				d[j] = d[k] + a[k][j];
		}
	}
	printf("a->");
	for (i = 2; i < n; i++) {
		printf("%d->", d[i]);
	}
	printf("%d\n", d[n]);
	return 0;
}


