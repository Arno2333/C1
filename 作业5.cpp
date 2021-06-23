#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#define MAX 100000
using namespace std;

//点结构
struct point {
	double x, y;
}p[MAX];

int a[MAX];			//保存排序索引

//距离
double distance(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmpx(const point a, const point b) {
	return a.x < b.x;
}

bool cmpy(int &a, int &b) {
	return p[a].y < p[b].y;
}

//最近点对
double closeset(point p[], int low, int high) {
	if (low == high)
		return MAX;
	if (low + 1 == high)
		return distance(p[low], p[high]);
	int mid = (low + high) / 2;
	double ans = min(closeset(p, low, mid), closeset(p, mid + 1, high));
	int i, j, s = 0;
	for (i = low; i <= high; i++) {
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			a[s++] = i;
	}
	sort(a, a + s, cmpy);

	for (i = 0; i < s; i++) {
		int k = i + 7 > s ? s : i + 7;
		for (j = i + 1; j < k; j++) {
			if (p[a[j]].y - p[a[i]].y > ans)
				break;
			ans = min(distance(p[a[i]], p[a[j]]), ans);
		}
	}
	return ans;
}

int main() {
	int n, i = 0;
	cout << "输入点的个数：";
	cin >> n;
	point *p = new point[n];
	ifstream infile;
	infile.open("点.txt", ios::in);	//相对路径
	if (!infile.is_open()) {
		cout << "Error: Open file failure." << endl;
		system("pause");
		return 0;
	}

	while (!infile.eof() && i < n) {
		infile >> p[i].x >> p[i].y;
		i++;
	}
	infile.close();
	sort(p, p + n, cmpx);
	cout << "最近距离为：" << closeset(p, 0, n - 1) / 2 << endl;

	system("pause");
	return 0;
}
