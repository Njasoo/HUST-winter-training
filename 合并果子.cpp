#include<bits/stdc++.h>
using namespace std;
int last = 0;
long long h[100001];
void push(long long x) {
    last++;
    int size = last;
    h[size] = x;
    while (size != 1) {
        if (h[size] < h[size / 2]) {
            swap(h[size], h[size / 2]);
        } else {
            break;
        }
        size /= 2;
    }
}
long long pop() {
    long long res = h[1];
    int id = 1;
    h[1] = h[last];
    last--;
    while (id * 2 <= last) {
        if (h[id] <= h[id * 2] && h[id] <= h[id * 2 + 1]) break;
        if (h[id * 2] <= h[id * 2 + 1]) {
            swap(h[id], h[id * 2]);
            id = id * 2;
        } else {
            swap(h[id], h[id * 2 + 1]);
            id = id * 2 + 1;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        push(a);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        long long s1 = pop();
        long long s2 = pop();
        ans += s1 + s2;
        push(s1 + s2);
    }
    cout << ans << '\n';
    return 0;
}