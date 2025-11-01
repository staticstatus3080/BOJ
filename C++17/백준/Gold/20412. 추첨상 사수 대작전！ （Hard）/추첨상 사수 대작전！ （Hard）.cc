#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;
ll m, s, x1, x2;

ll mod(ll a) {
    if (a<0) return (a%m)+m;
    return a%m;
}

ll inv(ll a) {
    ll tmp=m-3, mul=a;
    while (tmp>0) {
        if (tmp&1) a *= mul;
        mul *= mul;
        a %= m;
        mul %= m;
        tmp/=2;
    }
    return a;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> m >> s >> x1 >> x2;
    ll b1 = mod(x2-x1), b2=mod(x1-s);
    ll a = b1*inv(b2)%m;
    ll t = a*x1%m;
    ll c = mod(x2-t);
    cout << a << ' ' << c;
}    