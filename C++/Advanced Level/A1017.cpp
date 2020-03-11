#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10000, H = 3600, M = 60;

struct Person {
    int aTime;
    int pTime;
};

int cmp(Person p1, Person p2) {
    return p1.aTime < p2.aTime;
}

int main() {
    int n, k, hh, mm, ss, processTime, arriveTime, ans = 0;
    scanf("%d %d", &n, &k);
    vector<Person> p;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &processTime);
        arriveTime = hh * H + mm * M + ss;
        if (arriveTime <= 17 * H) {
            p.push_back({arriveTime, processTime * M});
        }
    }
    sort(p.begin(), p.end(), cmp);
    vector<int> windows(k, 8 * H);
    for (int i = 0; i < p.size(); i++) {
        int minIndex = 0, minTime = windows[0];
        for (int j = 1; j < k; j++) {
            if (windows[j] < minTime) {
                minTime = windows[j];
                minIndex = j;
            }
        }
        if (p[i].aTime >= minTime) {
            windows[minIndex] = p[i].aTime + p[i].pTime;
        } else {
            ans += minTime - p[i].aTime;
            windows[minIndex] = minTime + p[i].pTime;
        }
    }
    if (p.size() == 0) {
        printf("0.0");
    } else {
        printf("%.1f", ans * 1.0 / M / p.size());
    }
    return 0;
}

/*
按时间一秒一秒考虑 
最后一个测试点没过 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 10000, H = 3600, M = 60;
int n, k, ans = 0;

struct Person {
    int aTime;
    int pTime;
} p[maxn];

int cmp(Person p1, Person p2) {
    return p1.aTime < p2.aTime;
}

int main() {
    scanf("%d %d", &n, &k);
    int hh, mm, ss, time, index = 0;
    queue<Person> que;
    vector<Person> proc;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p[i].pTime);
        p[i].aTime = hh * H + mm * M + ss;
        p[i].pTime *= M;
        if (p[i].pTime > H) {
            p[i].pTime = H;
        }
    }
    sort(p, p + n, cmp);
    time = p[0].aTime;
    while (time < 8 * H) {
        if (p[index].aTime == time) {
            que.push(p[index++]);
        }
        time++;
    }
    while (time <= 17 * H || !que.empty()) {
        for (int i = 0; i < proc.size(); i++) {
            proc[i].pTime--;
            if (proc[i].pTime == 0) {
                proc.erase(proc.begin() + i);
            }
        }
        if (time <= 17 * H && p[index].aTime == time) {
            que.push(p[index++]);
        }
        while (proc.size() < k && que.size() > 0) {
            Person temp = que.front();
            proc.push_back(temp);
            ans += time - temp.aTime;
            que.pop();
        }
        time++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].aTime <= 17 * H) {
            cnt++;
        }
    }
    printf("Cnt:%d\n", cnt);
    if (index == 0) {
        printf("0.0");
    } else {
        printf("%.1f", ans * 1.0 / M / index);
    }
    return 0;
}
*/
