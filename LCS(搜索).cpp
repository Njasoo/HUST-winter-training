#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<functional>
#include<ctime>
#include<cassert>
#include<numeric>
#include<bitset>
#include<iomanip>
#include<sstream>
using namespace std;
using cint=const int;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using mii=map<int,int>;
#define vt vector
#define all(bianliang) (bianliang).begin(),(bianliang).end()
#define rall(bianliang) (bianliang).rbegin(),(bianliang).rend()
#define fi first
#define se second
#define pb push_back
#define sz(bianliang) (bianliang).size()

int n;
cint N=1005;
int a[N],b[N];
int LCS(int posa,int posb)
{
    if(posa>n||posb>n) return 0;
    if(a[posa]==b[posb]) return 1+LCS(posa+1,posb+1);
    return max(LCS(posa+1,posb),LCS(posa,posb+1));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    cout<<LCS(1,1)<<'\n';
    return 0;
}