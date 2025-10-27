#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;
// https://justicehui.github.io/ 강의자료 참고

// [g,x,y] -> ax+by = gcd(a,b) = g
tuple<ll,ll,ll> ext_gcd(ll a, ll b) {
    if (b==0) return {a,1,0};
    auto [g,x,y] = ext_gcd(b, a%b);
    return {g, y, x-a/b*y};
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, g, x, y;
        cin >> a >> b;
        if (a==1 && b==1) {
            cout << 2 << '\n';
            continue;
        }
        tie(g,x,y) = ext_gcd(a, b);
        while (y<=0) y+=a;
        if (x==0) {
            y *= (a+1);
        }
        if (g!=1 || y>1e9) cout << "IMPOSSIBLE\n";
        else cout << y << '\n';
    }
}    