#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// 按照冲突值排序
const int N = 2e5 + 5;
int n, m;
int f[N << 1];
struct Edge {
    int from, to, cost;
};
bool cmp(Edge i, Edge j) {
    return i.cost > j.cost;
}
int leader(int x) {
    if (x == f[x]) return x;
    return x = f[x] = leader(f[x]);
}
void merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    f[y] = x;
}
bool same(int x, int y) {
    return leader(x) == leader(y);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= (n << 1); i++) {
        f[i] = i;
    }
    vector<Edge> p;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        p.push_back({a, b, c});
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < (int) p.size(); i++) {
        int a = p[i].from;
        int b = p[i].to;
        int c = p[i].cost;
        if (!same(a, b)) {
            merge(a, b + n); // 敌人的敌人就是朋友
            merge(b, a + n);
        } else { // 不可避免地要在同一个监狱
            cout << c << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}