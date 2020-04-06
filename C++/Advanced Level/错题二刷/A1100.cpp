#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
string num[4];
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> marsToNum;
string numToMars[170];

void init() {
    for (int i = 0; i < 13; i++) {
        numToMars[i] = unitDigit[i];
        marsToNum[unitDigit[i]] = i;
        numToMars[i * 13] = tenDigit[i];
        marsToNum[tenDigit[i]] = i * 13;
    }
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j++) {
            string mars = tenDigit[i] + " " + unitDigit[j];
            numToMars[i * 13 + j] = mars;
            marsToNum[mars] = i * 13 + j;
        }
    }
}

int main() {
    scanf("%d", &n);
    getchar();
    string str;
    init();
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        if (str[0] >= '0' && str[0] <= '9') {
            printf("%s\n", numToMars[stoi(str)].c_str());
        } else {
            printf("%d\n", marsToNum[str]);
        }
    }
    return 0;
}
