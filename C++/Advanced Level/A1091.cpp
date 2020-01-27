#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int z;
} node;

int m, n, l, t;
int volume[60][1286][128];
bool inq[60][1286][128];
int X[6] = {0, 0, -1, 1, 0, 0};
int Y[6] = {-1, 1, 0, 0, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int i, int j, int k) {
    if (i >= l || i < 0 || j >= m || j < 0 || k >= n || k < 0) {
        return false;
    }
    if (volume[i][j][k] == 0 || inq[i][j][k] == true) {
        return false;
    }
    return true;
}

int BFS(int z, int y, int x) {
    queue<Node> q;
    node.x = x;
    node.y = y;
    node.z = z;
    q.push(node);
    inq[z][y][x] = true;
    int count = 1;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int new_x = top.x + X[i];
            int new_y = top.y + Y[i];
            int new_z = top.z + Z[i];
            if (judge(new_z, new_y, new_x)) {
                node.x = new_x;
                node.y = new_y;
                node.z = new_z;
                q.push(node);
                inq[new_z][new_y][new_x] = true;
                count++;
            }
        }
    }
    if (count >= t) {
        return count;
    } else {
        return 0;
    }
}

int main() {
    int ans = 0;
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &volume[i][j][k]);
            }
        }
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (volume[i][j][k] == 1 && judge(i, j, k) == true) {
                    ans += BFS(i, j, k);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
