#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int M = 2e5 + 5;
const int K = 1e6;
int cnt = 0, ans;
int head[N];
bool vis[N];
struct Edge {
    int from, to, next;
}e[M + M];
void add_edge(int u, int v) {
    cnt++;
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int n, m;
void dfs(int u) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!vis[v]) {
            vis[v] = 1;
            ans++;
            if (ans >= K) return;
            dfs(v);
            vis[v] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    vis[1] = 1;
    ans = 1;
    dfs(1);
    cout << min(K, ans) << '\n';
    return 0;
}