#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int len = i; // 当前二叉堆节点个数
        while (len != 1) {
            if (a[len] < a[len / 2]) { // 与父节点比较
                swap(a[len], a[len / 2]); // 小于父节点就交换
            } else {
                break;
            }
            len /= 2; // 往上走
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[1] << " "; // 根节点为最小的值
        a[1] = a[n - i + 1]; // a[n - i + 1]当前堆的最后一个节点
        int id = 1;
        while (id * 2 <= n - i) { // 先插入的是左节点，所以判断左节点有无越界就行
            if (a[id] <= a[id * 2] && a[id] <= a[id * 2 + 1]) break; // 如果根节点已经是最小的，那么不用往下遍历了
            if (a[id * 2] < a[id * 2 + 1]) { // 与值更小的节点交换
                swap(a[id], a[id * 2]);
                id = id * 2;
            } else {
                swap(a[id], a[id * 2 + 1]);
                id = id * 2 + 1;
            }
        }
    }
    return 0;
}