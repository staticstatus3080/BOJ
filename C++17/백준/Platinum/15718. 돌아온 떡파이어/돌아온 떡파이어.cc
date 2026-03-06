#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

// https://justicehui.github.io/ 강의자료 참고
ll mod(ll a, ll b) {return (a%b>=0) ? a : a+b;}
// [g,x,y] -> ax+by = gcd(a,b) = g
tuple<ll,ll,ll> ext_gcd(ll a, ll b) {
    if (b==0) return {a,1,0};
    auto [g,x,y] = ext_gcd(b, a%b);
    return {g, y, x-a/b*y};
}
pair<ll,ll> crt(ll a1, ll m1, ll a2, ll m2){
    ll g = gcd(m1, m2), m = m1 / g*m2;
    if((a2-a1)%g) return {-1, -1};
    ll mul = mod((a2-a1)/g,m2);
    ll x = mod(get<1>(ext_gcd(m1,m2)), m2) * mul % m2;
    return {(a1+x*m1)%m, m};
}
pair<ll,ll> crt(const vector<ll> &a, const vector<ll> &m){
    ll ra = a[0], rm = m[0];
    for (int i=1; i<m.size(); i++) {
        auto [aa,mm] = crt(ra, rm, a[i], m[i]);
        if (mm == -1) return {-1, -1}; else tie(ra,rm) = tie(aa,mm);
    }
    return {ra, rm};
}

vector<ll> v1, v2;
ll multiply(ll a, ll b, ll m) {
    ll ret=1, tmp=a;
    while (b>0) {
        if (b%2==1) ret *= tmp;
        tmp *= tmp;
        tmp %= m;
        ret %= m;
        b /= 2;
    }
    return ret;
}
ll calc(ll n, ll k, ll m) {
    ll a=1, b=1;
    for (int i=n; i>(n-k); i--) {
        a *= i;
        a %= m;
    }
    for (int i=1; i<=k; i++) {
        b *= i;
        b %= m;
    }
    a = a*multiply(b, m-2, m);
    return a%m;
}
void nCr(ll n, ll k, ll m) {
    ll ans = 1;
    while (n>0) {
        ll tmpn = n%m, tmpk = k%m;
        ans *= calc(tmpn, tmpk, m);
        ans %= m;
        n /= m;
        k /= m;
    }
    v1.push_back(ans);
    v2.push_back(m);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        v1.clear();
        v2.clear();
        ll n, m;
        cin >> n >> m;
        if (n==0 && m==1) {
            cout << 1 << '\n';
            continue;
        }
        m--;
        n -= m;
        // 여기서 mHn을 구해야함 : 즉, m개 박스중 n개의 수를 선택
        if (n<0 || m<=0) {
            cout << 0 << '\n';
            continue;
        }
        if (n==0) {
            cout << 1 << '\n';
            continue;
        }
        m = n+m-1;
        nCr(m, n, 97);
        nCr(m, n, 1031);
        auto [a,b] = crt(v1, v2);
        cout << a << '\n';
    }
}