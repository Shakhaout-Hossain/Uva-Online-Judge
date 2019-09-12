#include<bits/stdc++.h>
#include <vector>
#define REP(i,n) for (ll i = 1; i <= n; i++)
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
ll MOD = 1000000007,a,b, p[100], v[100];
ll K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
// returns the N-th term of Fibonacci sequence
ll fib(ll N)
{
    // create vector F1
    vector<ll> F1(K+1);
    for(ll i=1, j=K; i<=K;j--, i++){
        F1[i]=v[j]%MOD;
    }
    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    for(ll i=1; i<=K; i++){
        for(ll j=1; j<=K; j++){
            T[i][j]=0;
        }
    }
    for(ll i=1; i<=K; i++)
        T[1][i]=p[i];
    for(ll i=2; i<=K; i++){
        T[i][i-1]=1;
    }
    if (N == 1)
        return v[1]%MOD;
    T = pow(T, N-K);
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int main()
{
    ll t, i, j, m,n, d;

    while(1){
        scanf("%lld%lld%lld",&d, &n, &MOD);
        if(d==0&&n==0&&MOD==0)return 0;
        K=d;
        for(j=1; j<=d; j++){
            scanf("%lld",&p[j]);
        }
        for(j=1; j<=d; j++){
            scanf("%lld",&v[j]);
        }
        //cout << p << endl;
        printf("%lld\n",fib(n));
    }
    return 0;
}
