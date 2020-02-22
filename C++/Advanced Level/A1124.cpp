#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, bool> names;
int m, n, s;

int main() {
    scanf("%d %d %d", &m, &n, &s);
    string name;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        cin >> name;
        if (i >= s && (i - s) % n == 0) {
            if (names[name] == false) {
                names[name] = true;
                flag = true;
                cout << name << endl;
            } else {
                s++;
            }
        }
    }
    if (flag == false) {
        printf("Keep going...");
    }
    return 0;
}
