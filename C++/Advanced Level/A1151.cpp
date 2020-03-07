#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10001;
int m, n, in[maxn], pre[maxn];
map<int, int> index;

void LCA(int preL, int inL, int inR, int v1, int v2) {
    if (inL > inR) {
        return;
    }
    int rootIndex = index[pre[preL]], index1 = index[v1], index2 = index[v2];
    if ((rootIndex > index1 && rootIndex < index2) || (rootIndex > index2 && rootIndex < index1)) {
        printf("LCA of %d and %d is %d.\n", v1, v2, pre[preL]);
    } else if (rootIndex > index1 && rootIndex > index2) {
        LCA(preL + 1, inL, rootIndex - 1, v1, v2);
    } else if (rootIndex < index1 && rootIndex < index2) {
        LCA(preL + (rootIndex - inL) + 1, rootIndex + 1, inR, v1, v2);
    } else if (rootIndex == index1) {
        printf("%d is an ancestor of %d.\n", v1, v2);
    } else if (rootIndex == index2) {
        printf("%d is an ancestor of %d.\n", v2, v1);
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        index[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pre[i]);
    }
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        if (index[v1] == 0 && index[v2] == 0) {
            printf("ERROR: %d and %d are not found.\n", v1, v2);
        } else if (index[v1] == 0 || index[v2] == 0) {
            printf("ERROR: %d is not found.\n", index[v1] == 0 ? v1 : v2);
        } else {
            LCA(1, 1, n, v1, v2);
        }
    }
    return 0;
}
