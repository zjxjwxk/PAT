#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, k, count = 0;
map<string, map<string, int> > G;
map<string, bool> vis;
map<string, int> heads;

void DFS(string name, int &total_time, int max_time, string &head, int &amount) {
    if (vis[name] == false) {
        map<string, int> v = G[name];
        map<string, int>::iterator it;
        int temp_total = 0;
        for (it = v.begin(); it != v.end(); it++) {
            total_time += it->second;
            temp_total += it->second;
        }
        if (temp_total > max_time) {
            max_time = temp_total;
            head = name;
        }
        vis[name] = true;
        amount++;
        for (it = v.begin(); it != v.end(); it++) {
            if (vis[it->first] == false && G[it->first].size() > 0) {
                DFS(it->first, total_time, max_time, head, amount);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    string name1, name2;
    int time;
    for (int i = 0; i < n; i++) {
        cin >> name1 >> name2 >> time;
        if (G.count(name1) == 0 && G.count(name2) == 0) {
            map<string, int> v1, v2;
            v1[name2] = v2[name1] = time;
            G[name1] = v1;
            G[name2] = v2;
            vis[name1] = vis[name2] = false;
        } else if (G.count(name1) != 0 && G.count(name2) == 0) {
            G[name1][name2] = time;
            map<string, int> v2;
            v2[name1] = time;
            G[name2] = v2;
            vis[name2] = false;
        } else if (G.count(name1) == 0 && G.count(name2) != 0) {
            G[name2][name1] = time;
            map<string, int> v1;
            v1[name2] = time;
            G[name1] = v1;
            vis[name1] = false;
        } else {
            G[name1][name2] += time;
            G[name2][name1] += time;
        }
    }
    for (map<string, map<string, int> >::iterator it = G.begin(); it != G.end(); it++) {
        string head;
        int total_time = 0, amount = 0;
        if (vis[it->first] == false) {
            DFS(it->first, total_time, 0, head, amount);
        }
        if (total_time / 2 > k && amount > 2) {
            count++;
            heads[head] = amount;
        }
    }
    cout << count << endl;
    for (map<string, int>::iterator it = heads.begin(); it != heads.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
