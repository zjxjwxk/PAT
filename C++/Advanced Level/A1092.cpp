#include <cstdio>
#include <cstring>

int main() {
    char shop[1001];
    char want[1001];
    scanf("%s", shop);
    scanf("%s", want);
    int hash_table[128] = {0};
    int len1 = strlen(shop);
    int len2 = strlen(want);
    for (int i = 0; i < len1; i++) {
        hash_table[shop[i]]++;
    }
    for (int i = 0; i < len2; i++) {
        hash_table[want[i]]--;
    }
    int miss = 0, extra = 0;
    for (int i = 0; i < 128; i++) {
        if (hash_table[i] < 0) {
            miss += -hash_table[i];
        } else if (hash_table[i] > 0) {
            extra += hash_table[i];
        }
    }
    if (miss == 0) {
        printf("Yes %d", extra);
    } else {
        printf("No %d", miss);
    }
    return 0;
}
