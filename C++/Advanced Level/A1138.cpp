#include <cstdio>

const int maxn = 50000;
int n, pre[maxn], in[maxn];
bool flag = false;

void postorder(int preL, int inL, int inR) {
    if (inL > inR || flag == true) {
        return;
    }
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int num = k - inL;
    postorder(preL + 1, inL, k - 1);
    postorder(preL + 1 + num, k + 1, inR);
    if (flag == false) {
        printf("%d", pre[preL]);
        flag = true;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    postorder(0, 0, n - 1);
    return 0;
}
