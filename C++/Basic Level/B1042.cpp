#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int hash_table[26] = {0};
    char str[1001];
    cin.getline(str, 1001);
    int len = strlen(str);
    int max = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] -= 'A';
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 'a';
            }
            hash_table[str[i]]++;
            if (hash_table[str[i]] > max) {
                max = hash_table[str[i]];
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (hash_table[i] == max) {
            printf("%c %d", i + 'a', hash_table[i]);
            break; 
        }
    }
    return 0;
}
