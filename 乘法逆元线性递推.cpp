#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//k*i+r=0(mod p)
//两边同时乘以i^-1,r^-1
//k*r^-1+i^-1=0(mod p)
//i^-1=-k*r^-1(mod p)
//i^-1=-[p/i]*(p%i)^-1(mod p)#p%i肯定在之前已经计算过所以可以用递推
//1^-1=1(mod p)
const int N=3e6+5;
ll inv[N];
int main() {
    ll n,p;
    scanf("%lld%lld",&n,&p);
    inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        inv[i]=p-p/i*inv[p%i]%p;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld\n",inv[i]);
    }
    return 0;
}