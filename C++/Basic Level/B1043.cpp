#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

int main() {
    char str[10001];
    int hash_table[6] = {0};
    scanf("%s", str);
    int len = strlen(str);
    map<char, int> map;
    map['P'] = 0;
    map['A'] = 1;
    map['T'] = 2;
    map['e'] = 3;
    map['s'] = 4;
    map['t'] = 5;
    int output[6] = {'P', 'A', 'T', 'e', 's', 't'};
    for (int i = 0; i < len; i++) {
        if (map.count(str[i]) != 0) {
            hash_table[map[str[i]]]++;
        }
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < 6; i++) {
            if (hash_table[i] > 0) {
                printf("%c", output[i]);
                hash_table[i]--;
                flag = true;
            }
        }
    }
    return 0;
}
