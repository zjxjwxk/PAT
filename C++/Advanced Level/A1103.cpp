#include <cstdio>
#include <vector>
using namespace std;

int n, k, p;
vector<int> ans, temp, fac;
int max_fac_sum = 0;

int power(int x) {
    int ans = 1;
    for (int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}

void init() {
    int i = 0, temp = 0;
    while (temp <= n) {
        fac.push_back(temp);
        temp = power(++i);
    }
}

void DFS(int num, int sum, int now_k, int fac_sum) {
    if (sum == n && now_k == k) {
        if (fac_sum > max_fac_sum) {
            ans = temp;
            max_fac_sum = fac_sum;
        }
        return;
    }
    if (num == 0 || sum > n || now_k > k) {
        return;
    }
    temp.push_back(num);
    DFS(num, sum + fac[num], now_k + 1, fac_sum + num);
    temp.pop_back();
    DFS(num - 1, sum, now_k, fac_sum);
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    init();
    DFS(fac.size() - 1, 0, 0, 0);
    if (ans.size() == 0) {
        printf("Impossible");
    } else {
        printf("%d = ", n);
        for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
            printf("%d^%d", *it, p);
            if (it + 1 != ans.end()) {
                printf(" + ");
            }
        }
    }
    return 0;
}
