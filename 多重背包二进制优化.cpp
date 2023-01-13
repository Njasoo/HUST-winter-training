#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=2e6+5;
const int M=2005;
int v[N],w[N];
int dp[M];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=1;j<=c;j<<=1)
        {
            cnt++;
            v[cnt]=j*a;
            w[cnt]=j*b;
            c-=j;
        }
        if(c)
        {
            cnt++;
            v[cnt]=c*a;
            w[cnt]=c*b;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<'\n';
    return 0;
}