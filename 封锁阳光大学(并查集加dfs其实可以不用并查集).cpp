#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, m;
const int N = 1e4 + 5;
const int M = 1e5 + 5;
struct Edge {
    int from, to, cost, next;
}e[M << 1];
int cnt = 0;
int head[N];
void add_edge(int u, int v) {
    cnt++;
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
bool flag = 1;
bool vis[N];
int c[N], sum[2];
void dfs(int u, int col) {
    sum[c[u] = col]++;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (vis[v]) {
            if (c[v] == col) flag = 0;
            continue;
        }
        dfs(v, col ^ 1);
    }
}
int f[N];
int leader(int x) {
    if (f[x] == x) return x;
    return x = f[x] = leader(f[x]);
}
void merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    f[y] = x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(c, -1, sizeof(c));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
        merge(u, v);
    }
    queue<int> fathers;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            // cerr << i << " ";
            fathers.push(i);
        }
    }
    int ans = 0;
    while (!fathers.empty()) {
        // memset(c, -1, sizeof(-1));
        int s = fathers.front();
        // cerr << s << " ";
        fathers.pop();
        dfs(s, 0);
        ans += min(sum[0], sum[1]);
        sum[0] = sum[1] = 0;
    }
    if (!flag) {
        cout << "Impossible\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}