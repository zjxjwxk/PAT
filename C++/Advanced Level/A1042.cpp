#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void shuffle(string cards[2][54], int order[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 54; j++) {
            if (i % 2 == 0) {
                cards[1][order[j] - 1] = cards[0][j];
            } else {
                cards[0][order[j] - 1] = cards[1][j];
            }
        }
    }
}

int main() {
    string type[4] = {"S", "H", "C", "D"};
    string cards[2][54];
    int order[54];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            cards[0][k++] = type[i] + to_string(j);
        }
    }
    cards[0][k++] = "J1";
    cards[0][k] = "J2";
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 54; i++) {
        scanf("%d", &order[i]);
    }
    shuffle(cards, order, n);
    int j = n % 2;
    for (int i = 0; i < 54; i++) {
        cout << cards[j][i];
        if (i != 53) {
            cout << " ";
        }
    }
    return 0;
}
