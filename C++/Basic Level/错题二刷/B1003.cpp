#include <cstdio>
#include <cstring>

const int maxn = 101;

int main() {
    int n, len;
    scanf("%d", &n);
    char str[maxn];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        len = strlen(str);
        int PNum = 0, TNum = 0, otherNum = 0, PIndex, TIndex;
        for (int j = 0; j < len; j++) {
            if (str[j] == 'P') {
                PNum++;
                PIndex = j;
            } else if (str[j] == 'T') {
                TNum++;
                TIndex = j;
            } else if (str[j] != 'A') {
                otherNum++;
            }
        }
        if (PNum != 1 || TNum != 1 || otherNum != 0 || (TIndex - PIndex) <= 1) {
            printf("NO\n");
            continue;
        }
        int leftA = PIndex, midA = TIndex - PIndex - 1, rightA = len - TIndex - 1;
        if (leftA * midA == rightA) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
