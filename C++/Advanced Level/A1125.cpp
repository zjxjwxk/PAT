#include <cstdio>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        q.push(num);
    }
    while (q.size() >= 2) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push((a + b) / 2);
    }
    printf("%d", q.top());
    return 0;
}
