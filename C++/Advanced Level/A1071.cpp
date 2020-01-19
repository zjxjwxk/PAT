#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string, int> count_map;

int main() {
    char c;
    string word;
    int max_count = 0;
    string max_word;
    bool flag = false;
    do {
        scanf("%c", &c);
        if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            word += c;
            flag = true;
        } else {
            if (flag == true) {
                if (count_map.count(word) == 0) {
                    count_map[word] = 1;
                } else {
                    count_map[word]++;
                }
                if (count_map[word] > max_count) {
                    max_count = count_map[word];
                    max_word = word;
                }
                word.clear();
                flag = false;
            }
        }
    } while (c != '\n');
    printf("%s %d", max_word.c_str(), max_count);
    return 0;
}
