#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 101;

int main() {
    int n, index, s[maxn] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie;
            int a[maxn];
            fill(a, a + maxn, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++) {
                if (s[k] * a[abs(s[k])] < 0) {
                    lie.push_back(k);
                }
            }
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
