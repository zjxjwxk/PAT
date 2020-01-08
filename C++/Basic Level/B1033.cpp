#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 100001;

bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}
                   
int main() {
    char wrong[maxn];
    char input[maxn];
    cin.getline(wrong, maxn);
    cin.getline(input, maxn);
    bool hash_table[128] = {false};
    int len1 = strlen(wrong);
    int len2 = strlen(input);
    for (int i = 0; i < len1; i++) {
        hash_table[wrong[i]] = true;
    }
    for (int i = 0; i < len2; i++) {
        char temp = input[i];
        if (isLower(input[i])) {
            temp -= 32;
            if (hash_table[temp] == false) {
                printf("%c", input[i]);
            }
        } else if (isUpper(input[i])) {
            if (hash_table['+'] == false && hash_table[input[i]] == false) {
                printf("%c", input[i]);
            }
        } else if (hash_table[input[i]] == false) {
            printf("%c", input[i]);
        }
    }
    printf("\n");
    return 0;
}

