#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=10005,M=105;
int v[N],w[N];
int dp[N][M];
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=1;j<=c;j++)
        {
            cnt++;
            v[cnt]=a;
            w[cnt]=b;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j>=v[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[cnt][m]<<'\n';
    return 0;
}