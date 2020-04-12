#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1011, INF = 1000000000;
int n, m, k, ds, G[maxn][maxn], d[maxn], minD = 0, minG = -1;
double minAvgD = INF;
bool vis[maxn] = {false};

int getIndex(char str[]) {
	int i = 0, index = 0;
	if (str[0] == 'G') {
		i++;
	}
	while (str[i] != '\0') {
		index = index * 10 + str[i] - '0';
		i++;
	}
	if (str[0] == 'G') {
		return n + index;
	} else {
		return index;
	}
}

void Dijkstra(int root) {
	fill(d, d + maxn, INF);
	fill(vis, vis + maxn, false);
	d[root] = 0;
	for (int i = 1; i <= n + m; i++) {
		int u = -1, min = INF;
		for (int j = 1; j <= n + m; j++) {
			if (vis[j] == false && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) {
			return;
		}
		vis[u] = true;
		for (int v = 1; v <= n + m; v++) {
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	fill(G[0], G[0] + maxn * maxn, INF);
	char str1[4], str2[4];
	int v1, v2, dist;
	for (int i = 0; i < k; i++) {
		scanf("%s %s %d", str1, str2, &dist);
		v1 = getIndex(str1);
		v2 = getIndex(str2);
		G[v1][v2] = G[v2][v1] = dist;
	}
	for (int i = n + 1; i <= n + m; i++) {
		Dijkstra(i);
		double tempAvgD = 0;
		int tempMinD = INF;
		for (int j = 1; j <= n; j++) {
			if (d[j] > ds) {
				tempMinD = -1; 
				break;
			}
			if (d[j] < tempMinD) {
				tempMinD = d[j];
			}
			tempAvgD += 1.0 * d[j] / n;
		}
		if (tempMinD != -1) {
			if (tempMinD > minD) {
				minD = tempMinD;
				minG = i - n;
				minAvgD = tempAvgD;
			} else if (tempMinD == minD && tempAvgD < minAvgD) {
				minG = i - n;
				minAvgD = tempAvgD;
			}
		}
	}
	if (minG == -1) {
		printf("No Solution");
	} else {
		printf("G%d\n", minG);
		printf("%.1f %.1f", 1.0 * minD, minAvgD);
	}
	return 0;
}
