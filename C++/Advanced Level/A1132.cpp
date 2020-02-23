#include <cstdio>
#include <string>
using namespace std;

int main() {
    int n, digit;
    int z, temp, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &z);
        string str = to_string(z);
        int len = str.length();
        int a = stoi(str.substr(0, len / 2));
        int b = stoi(str.substr(len / 2));
        if (a * b != 0 && z % (a * b) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
