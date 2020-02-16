#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1020;
int k, hash_table[256] = {0}, hash_table2[256] = {0};
char str[maxn];

int main() {
    scanf("%d", &k);
    scanf("%s", str);
    int len = strlen(str), count = 1;
    for (int i = 0; i < len; i++) {
        if (str[i + 1] == str[i]) {
            count++;
        } else {
            if (count % k == 0 && hash_table[str[i]] != -1) {
                hash_table[str[i]] = 1;
            } else {
                hash_table[str[i]] = -1;
            }
            count = 1;
        }
    }
    vector<char> ans1, ans2;
    for (int i = 0; i < len; i++) {
        if (hash_table[str[i]] == 1) {
            ans2.push_back(str[i]);
            if (hash_table2[str[i]] == 0) {
                ans1.push_back(str[i]);
                hash_table2[str[i]] = 1;
            }
            i += k - 1;
        } else {
            ans2.push_back(str[i]);
        }
    }
    for (int i = 0; i < ans1.size(); i++) {
        printf("%c", ans1[i]);
    }
    printf("\n");
    for (int i = 0; i < ans2.size(); i++) {
        printf("%c", ans2[i]);
    }
    return 0;
}
