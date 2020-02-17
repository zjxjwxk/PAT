#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n, dists[maxn];

int cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dists[i]);
    }
    sort(dists, dists + n, cmp);
    int i;
    for (i = 0; i < n; i++) {
        if (dists[i] <= i + 1) {
            break;
        }
    }
    printf("%d", i);
    return 0;
}
