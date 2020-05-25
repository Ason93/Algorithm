#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
#define mod 1000000007
using namespace std;

ll n , q, x , sum , cur, x1, x2, x3;
ll a[maxn] , fac[maxn] , c[maxn][maxn] , f[3][maxn];

void Pre(){
    fac[0] = 1;
    for(int i = 1; i <= n; i ++)fac[i] = 1ll*i*fac[i-1] % mod;
    c[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j < i; j ++)
            c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % mod;
        c[i][0] = c[i][i] = 1;
    }
    return;
}

int main(){
    cin >> x1 >> x2 >> x3;
//    for(int i = 1; i <= n; i ++)
    a[1] = x1;
    a[2] = x2;
    a[3] = x3;
    n = 3;
    Pre();
    sum = 0; cur = 0;
    f[cur][0] = 1;
    for(int i = 1; i <= n; i ++){
        cur ^= 1;
        for(int t = 0; t <= a[i]+sum+1; t ++)
            f[cur][t] = 0;
        for(int k = 1; k <= a[i] && k <= sum+1; k ++)
            for(int j = 0; j <= sum; j ++)
                for(int l = 0; l <= k && l <= j; l ++){
                    f[cur][j-l+a[i]-k] +=
                            1ll*f[cur^1][j]*c[a[i]-1][k-1]%mod*(1ll*c[j][l]*c[sum+1-j][k-l]%mod)%mod;
                    f[cur][j-l+a[i]-l] %= mod;
                }
        sum += a[i];
    }
    cout<<f[cur][0]; return 0;
}