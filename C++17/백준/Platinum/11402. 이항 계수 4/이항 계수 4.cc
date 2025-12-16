#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

ll mod;

ll multiply(ll a, ll b) {
    ll ret=1, tmp=a;
    while (b>0) {
        if (b%2==1) ret *= tmp;
        tmp *= tmp;
        tmp %= mod;
        ret %= mod;
        b /= 2;
    }
    return ret;
}

ll nCr(ll n, ll k) {
    ll a=1, b=1;
    for (int i=n; i>(n-k); i--) {
        a *= i;
        a %= mod;
    }
    for (int i=1; i<=k; i++) {
        b *= i;
        b %= mod;
    }
    a = a*multiply(b, mod-2);
    return a%mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n, k, ans=1;
    cin >> n >> k >> mod;
    while (n>0) {
        ll tmpn = n%mod, tmpk = k%mod;
        ans *= nCr(tmpn, tmpk);
        ans %= mod;
        n /= mod;
        k /= mod;
    }
    cout << ans;
}