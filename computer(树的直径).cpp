#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
// 随便找一个点，离它最远的一个点必然是直径中的其中一个端点，根据这个端点我们再去找另一个端点，两个端点的距离就是树的直径
ll max(ll a, ll b) {
    return a > b ? a : b;
}
struct Edge {
    int from, to, cost, next;
}e[N << 1];
int cnt = 0;
int head[N];
void add_edge(int u, int v, int w) {
    cnt++;
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int dis1[N], dis2[N];
int maxv;
void dfs(int u, int fa, int d[]) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa) continue;
        d[v] = d[u] + e[i].cost;
        if (d[v] > d[maxv]) maxv = v;
        dfs(v, u, d);
    }
}
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(head, 0, sizeof(head)); // 记得
        for (int i = 2; i <= n; i++) {
            int v, w;
            scanf("%d %d", &v, &w);
            add_edge(i, v, w);
            add_edge(v, i, w);
        }
        int s = 1;
        maxv = 1;
        dfs(s, 0, dis1);
        s = maxv;
        dis1[s] = 0; // 记得
        dfs(s, 0, dis1);
        s = maxv;
        dis2[s] = 0; // 记得
        dfs(s, 0, dis2);
        for (int i = 1; i <= n; i++) {
            printf("%lld\n", max(dis1[i], dis2[i]));
        }
    }
    return 0;
}