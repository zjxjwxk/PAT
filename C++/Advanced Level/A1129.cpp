#include <cstdio>
#include <set>
using namespace std;

const int maxn = 50001;

struct Item {
    int indice;
    int cnt;
    bool operator < (const Item &a) const {
        if (cnt != a.cnt) {
            return cnt > a.cnt;
        } else {
            return indice < a.indice;
        }
    }
};

int main() {
    int n, k, indice, cnts[maxn] = {0};
    scanf("%d %d", &n, &k);
    set<Item> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &indice);
        if (i != 0) {
            printf("%d:", indice);
            int temp_cnt = 0;
            for (auto it = s.begin(); it != s.end() && temp_cnt < k; it++) {
                printf(" %d", it->indice);
                temp_cnt++;
            }
            printf("\n");
        }
        auto it = s.find(Item{indice, cnts[indice]});
        if (it != s.end()) {
            s.erase(it);
        }
        cnts[indice]++;
        s.insert(Item{indice, cnts[indice]});
    }
    return 0;
}
