#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// 从其他点回到一个定点的最短路程之和，可以考虑建反图，然后就变成了单源最短路问题了，求单点到其他点的最短距离
const int N = 1e3 + 5, M = 1e5 + 5;
int n, m, cnt = 0;
int dis[N * 2], head[M * 2];
bool vis[N * 2];
struct Edge {
    int from, to, cost, next;
}e[M * 2];
struct node {
    int w, now;
    bool operator < (const node& x) const {
        return x.w < w;
    }
};
void add_edge(int u, int v, int w) {
    cnt++;
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
priority_queue<node> q;
void dijkstra(int s) {
    for (int i = 1; i <= n * 2; i++) {
        dis[i] = 1e9;
    }
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        int u = x.now;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if (dis[u] + e[i].cost < dis[v]) {
                dis[v] = dis[u] + e[i].cost;
                q.push({dis[v], v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v + n, u + n, w);
    }
    ll ans = 0;
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        ans += dis[i];
    }
    dijkstra(1 + n);
    for (int i = n + 2; i <= n + n; i++) {
        ans += dis[i];
    }
    cout << ans << '\n';
    return 0;
}