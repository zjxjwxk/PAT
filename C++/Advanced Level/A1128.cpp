#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1001;
int k, n;

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        int chess[maxn] = {false};
        bool ans = true;
        for (int j = 0; j < n; j++) {
            scanf("%d", &chess[j]);
            for (int t = 0; t < j; t++) {
                if (chess[j] == chess[t] || abs(chess[j] - chess[t]) == j - t) {
                    ans = false;
                    break;
                }
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
