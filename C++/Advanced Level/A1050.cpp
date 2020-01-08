#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10001;

int main() {
    char s1[maxn];
    char s2[maxn];
    cin.getline(s1, maxn);
    cin.getline(s2, maxn);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    bool hash_table[128] = {false};
    for (int i = 0; i < len2; i++) {
        hash_table[s2[i]] = true;
    }
    for (int i = 0; i < len1; i++) {
        if (!hash_table[s1[i]]) {
            printf("%c", s1[i]);
        }
    }
    return 0;
}
