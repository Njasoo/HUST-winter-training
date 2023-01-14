#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, m;
int f[N][N], mark[N][N];
long long ans = 0, cnt = 0;
void dfs(int x, int y) {
    if (y == m + 1) {
        dfs(x + 1, 1);
        return;
    }
    if (x == n + 1) {
        ans = max(cnt, ans);
        return;
    }
    dfs(x, y + 1); // if I don't select this element, kind of like dp
    if (!mark[x][y]) {
        cnt += f[x][y];
        mark[x][y] = 1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i || j) mark[x + i][y + j]++; // 会有重叠的情况
            }
        }
        mark[x][y] = 0;
        dfs(x, y + 1);
        mark[x][y] = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i || j) mark[x + i][y + j]--;
            }
        }
        cnt -= f[x][y];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        memset(mark, 0, sizeof(mark));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> f[i][j];
            }
        }
        ans = 0;
        dfs(1, 1);
        cout << ans << "\n";
    }   
    return 0;
}