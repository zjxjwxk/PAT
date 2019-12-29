#include <cstdio>
#include <math.h>

int main() {
    int d[100010];
    int n, m, e1, e2;
    int dis[100010];
    dis[1] = 0;
    scanf("%d", &n);
    int total_distance = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        total_distance += d[i];
        dis[i + 1] = total_distance;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &e1, &e2);
        int distance = abs(dis[e2] - dis[e1]);
        printf("%d\n", distance < total_distance - distance ? distance : total_distance - distance);
    }
    return 0;
}
