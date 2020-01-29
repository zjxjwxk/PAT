#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int pre[30], in[30], count1 = 0, count2 = 0;
bool flag = false;

Node* create(int pre_left, int pre_right, int in_left, int in_right) {
    if (pre_left > pre_right) {
        return NULL;
    }
    Node* root = new Node;
    root->data = pre[pre_left];
    int k;
    for (k = in_left; k <= in_right; k++) {
        if (pre[pre_left] == in[k]) {
            break;
        }
    }
    int leftNum = k - in_left;
    root->left = create(pre_left + 1, pre_left + leftNum, in_left, k - 1);
    root->right = create(pre_left + leftNum + 1, pre_right, k + 1, in_right);
    return root;
}

void show_post(Node* root) {
    if (root == NULL) {
        return;
    }
    show_post(root->left);
    show_post(root->right);
    if (flag == false) {
        flag = true;
    } else {
        printf(" ");
    }
    printf("%d", root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    char str[5];
    int m = 2 * n, num;
    stack<int> s;
    while (m--) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) {
            scanf("%d", &num);
            s.push(num);
            pre[count1++] = num;
        } else {
            num = s.top();
            s.pop();
            in[count2++] = num;
        }
    }
    Node* root = create(0, n - 1, 0, n - 1);
    show_post(root);
    return 0;
}
