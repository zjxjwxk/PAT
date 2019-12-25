#include <cstdio>
#include <algorithm>
using namespace std;

struct moon_cake {
    double stock;
    double total_price;
    double avg_price;
} moon_cakes[1000];

bool cmp(moon_cake moon_cake1, moon_cake moon_cake2) {
    return moon_cake1.avg_price > moon_cake2.avg_price;
}

int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &moon_cakes[i].stock);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lf", &moon_cakes[i].total_price);
        moon_cakes[i].avg_price = moon_cakes[i].total_price / moon_cakes[i].stock;
    }
    sort(moon_cakes, moon_cakes + N, cmp);
    double total_profit = 0;
    double num = 0;
    for (int i = 0; i < N; i++) {
        if (num + moon_cakes[i].stock <= D) {
            num += moon_cakes[i].stock;
            total_profit += moon_cakes[i].total_price;
        } else {
            total_profit += (D - num) * moon_cakes[i].avg_price;
            break;
        }
    }
    printf("%.2lf", total_profit);
    return 0;
}
