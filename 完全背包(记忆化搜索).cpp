#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N=1005;
int v[N],w[N];
int dp[N][N];
int n,m;
int dfs(int now,int nowt)
{
    if(now>n) return 0;
    if(dp[now][nowt]!=-1) return dp[now][nowt];
    int res=dfs(now+1,nowt);//不选
    if(nowt>=v[now])
    {
        res=max(res,dfs(now,nowt-v[now])+w[now]);//选择第now个物品，继续递归做决策
    }
    return dp[now][nowt]=res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    cout<<dfs(1,m)<<'\n';
    return 0;
}