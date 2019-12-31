#include <cstdio>

const int galleon = 17 * 29;
const int sickle = 29;

int main() {
    int p1, p2, p3;
    int a1, a2, a3;
    scanf("%d.%d.%d", &p1, &p2, &p3);
    scanf("%d.%d.%d", &a1, &a2, &a3);
    int price = p1 * galleon + p2 * sickle + p3;
    int money = a1 * galleon + a2 * sickle + a3;
    int ans = money - price;
    if (ans < 0) {
        printf("-");
        ans = -ans;
    }
    printf("%d.%d.%d", ans / galleon, ans % galleon / sickle, ans % sickle);
    return 0;
}
