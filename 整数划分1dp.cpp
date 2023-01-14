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

//dp[i][j]:将i划分成j个的方案，当然每个数都是正整数
cint MOD=998244353;
cint N=105;
int dp[N][N];
int n,m;
// int dfs(int u,int v)
// {
//     if(u==0 && v==0) return 1;//没有东西要划分就是一种方案
//     if(u==0 || v==0) return 0;
//     if(dp[u][v]!=-1) return dp[u][v];
//     int res=0;
//     for(int i=1;i<=u;i++)
//     {
//         res+=dfs(u-i,v-1);
//         res%=MOD;
//     }
//     return dp[u][v]=res;
// }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=1;i+k<=n;k++)
            {
                dp[i+k][j+1]+=dp[i][j];
                dp[i+k][j+1]%=MOD;
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}