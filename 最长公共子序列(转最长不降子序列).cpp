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

cint N=1e5+5;
int b[N],to[N],dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        to[a]=i;
    }   
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        b[i]=to[b[i]];
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i-1;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(dp[mid]<=b[i]) l=mid+1,ans=mid;
            else r=mid-1;
        }
        dp[ans+1]=min(dp[ans+1],b[i]);
    }
    for(int i=n;i>=1;i--)
    {
        if(dp[i]!=0x3f3f3f3f)
        {
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}