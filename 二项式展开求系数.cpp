#include<bits/stdc++.h>
using namespace std;
const int MOD = 10007;
long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
long long c[10001][10001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    for (int i = 0; i < 1001; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= MOD;
        }
    }
    long long ans = c[k][m] * power(a, n) % MOD * power(b, m) % MOD;
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}