#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N = 2e5 + 5;
// 使一个数列变成有序的最小次数就是每个环的大小-1的总和
struct Dsu {
    int f[N], siz[N];
    Dsu(int n) {
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            siz[i] = 1;
        }
    }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return 0;
        f[y] = x;
        siz[x] += siz[y];
        return 1;
    } 
    int size(int x) { return siz[leader(x)]; }
};
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        Dsu dsu(n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dsu.merge(i, a[i]);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dsu.f[i] == i) { // 有多少个族长就代表多少个环
                cnt += dsu.size(i) - 1;
            }
        }
        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (dsu.same(a[i], a[i + 1])) { // 在同一个环内减少一次排序
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << cnt - 1 << '\n';
        } else {
            cout << cnt + 1 << '\n';
        }
    }   
    return 0;
}