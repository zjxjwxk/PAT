#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

string mars1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string mars2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

map<string, int> mars_to_num;
string num_to_mars[169];

void init() {
    for (int i = 0; i < 13; i++) {
        string str1 = mars1[i], str2 = mars2[i];
        mars_to_num[str1] = i;
        num_to_mars[i] = str1;
        mars_to_num[str2] = i * 13;
        num_to_mars[i * 13] = str2;
    }
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j++) {
            string str1 = mars2[i], str2 = mars1[j];
            mars_to_num[str1 + " " + str2] = i * 13 + j;
            num_to_mars[i * 13 + j] = str1 + " " + str2;
        }
    }
}

int to_num(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + str[i] - '0';
    }
    return num;
}

int main() {
    init();
    int n;
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') {
            printf("%s\n", num_to_mars[to_num(str)].c_str());
        } else {
            printf("%d\n", mars_to_num[str]);
        }
    }
    return 0;
}
