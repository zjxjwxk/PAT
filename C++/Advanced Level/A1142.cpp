#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 201;
int nv, ne, k;
bool G[maxn][maxn] = {false};

int main() {
    scanf("%d %d", &nv, &ne);
    int v1, v2;
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = true;
    }
    scanf("%d", &k);
    int num;
    for (int i = 0; i < k; i++) {
        scanf("%d", &num);
        int v;
        vector<int> temp;
        bool flag[maxn] = {false}, ifClique = true, ifMax = true;
        for (int j = 0; j < num; j++) {
            scanf("%d", &v);
            temp.push_back(v);
            flag[v] = true;
        }
        for (int j = 0; j < temp.size(); j++) {
            for (int t = j + 1; t < temp.size(); t++) {
                int v1 = temp[j], v2 = temp[t];
                if (G[v1][v2] == false) {
                    ifClique = false;
                    break;
                }
            }
            if (ifClique == false) {
                break;
            }
        }
        if (ifClique == true) {
            for (int j = 1; j <= nv; j++) {
                if (flag[j] == false) {
                    bool tempFlag = true;
                    for (int t = 0; t < num; t++) {
                        if (G[j][temp[t]] == false) {
                            tempFlag = false;
                            break;
                        }
                    }
                    if (tempFlag == true) {
                        ifMax = false;
                        break;
                    }
                }
            }
        }
        if (ifClique == false) {
            printf("Not a Clique\n");
        } else if (ifMax == false) {
            printf("Not Maximal\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
