#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 501, INF = 1000000000;
int cmax, n, sp, m, c[maxn], G[maxn][maxn], t[maxn], minNeed = INF, minBack = INF;
vector<int> path[maxn], temp, ans;
bool vis[maxn] = {false};

void Dijkstra() {
	fill(t, t + maxn, INF);
	t[0] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && t[j] < min) {
				min = t[j];
				u = j;
			}
		}
		if (u == -1) {
			return;
		}
		vis[u] = true;
		for (int v = 0; v <= n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (t[u] + G[u][v] < t[v]) {
					t[v] = t[u] + G[u][v];
					path[v].clear();
					path[v].push_back(u);
				} else if (t[u] + G[u][v] == t[v]) {
					path[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int root) {
	temp.push_back(root);
	if (root == 0) {
		int now = 0, need = 0;
		for (int i = temp.size() - 2; i >= 0; i--) {
			if (c[temp[i]] < cmax / 2) {
				if (now >= (cmax / 2 - c[temp[i]])) {
					now -= cmax / 2 - c[temp[i]];
				} else {
					need += cmax / 2 - c[temp[i]] - now;
					now = 0;
				}
			} else {
				now += c[temp[i]] - cmax / 2;
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minBack = now;
			ans = temp;
		} else if (need == minNeed) {
			if (now < minBack) {
				minBack = now;
				ans = temp;
			}
		}
		temp.pop_back();
		return;
	}
	for (int i = 0; i < path[root].size(); i++) {
		DFS(path[root][i]);
	}
	temp.pop_back();
}

int main() {
	scanf("%d %d %d %d", &cmax, &n, &sp, &m);
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	int s1, s2, t;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s1, &s2, &t);
		G[s1][s2] = G[s2][s1] = t;
	}
	Dijkstra();
	DFS(sp);
	printf("%d ", minNeed);
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d", ans[i]);
		if (i != 0) {
			printf("->");
		}
	}
	printf(" %d", minBack);
	return 0;
}
