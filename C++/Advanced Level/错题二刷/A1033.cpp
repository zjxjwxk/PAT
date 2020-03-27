#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 501;

struct Station {
    double P;
    double D;
} stations[maxn];

int cmp(Station s1, Station s2) {
    return s1.D < s2.D;
}

int main() {
    double capacity, destD, avgD, nowC = 0, nowD = 0, cost = 0;
    int n, nowIndex = 0;
    scanf("%lf %lf %lf %d", &capacity, &destD, &avgD, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &stations[i].P, &stations[i].D);
    }
    stations[n].P = 0;
    stations[n].D = destD;
    sort(stations, stations + n, cmp);
    if (stations[0].D != 0) {
        printf("The maximum travel distance = 0.00");
    } else {
        while (nowD < destD) {
            if (nowIndex == n - 1 && (capacity * avgD < (destD - nowD)) || (nowIndex < n - 1) && (capacity * avgD < (stations[nowIndex + 1].D - nowD))) {
                nowD += capacity * avgD;
                break;
            }
            double minP = stations[nowIndex].P, secondP = stations[nowIndex + 1].P;
            int minIndex = -1, secondIndex = nowIndex + 1;
            for (int i = nowIndex + 1; i <= n; i++) {
                if (capacity * avgD >= (stations[i].D - nowD)) {
                    if (stations[i].P < minP) {
                        minP = stations[i].P;
                        minIndex = i;
                        break;
                    } else if (stations[i].P < secondP) {
                        secondP = stations[i].P;
                        secondIndex = i;
                    }
                } else {
                    break;
                }
            }
            if (minIndex != -1) {
                if (nowC * avgD < (stations[minIndex].D - nowD)) {
                    cost += ((stations[minIndex].D - nowD) / avgD - nowC) * stations[nowIndex].P;
                    nowC = 0;
                } else {
                    nowC -= (stations[minIndex].D - nowD) / avgD;
                }
                nowD = stations[minIndex].D;
                nowIndex = minIndex;
            } else {
                cost += (capacity - nowC) * stations[nowIndex].P;
                nowC = capacity - (stations[secondIndex].D - nowD) / avgD;
                nowD = stations[secondIndex].D;
                nowIndex = secondIndex;
            }
        }
        if (nowD < destD) {
            printf("The maximum travel distance = %.2f", nowD);
        } else {
            printf("%.2f", cost);
        }
    }
    return 0;
}
