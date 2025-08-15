#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;

bool cmp(pii p1, pii p2) {
    ll rem1=p1.Y-p1.X, rem2=p2.Y-p2.X;
    if (rem1<0 && rem2<0) return p1.Y>p2.Y;
    if (rem1<0) return 0;
    if (rem2<0) return 1;
    return p1.X<p2.X;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> v;
    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    ll ans=0, rem=0;
    for (auto cur : v) {
        if (rem<cur.X) {ans+=(cur.X-rem); rem=0;}
        else rem-=cur.X;
        rem += cur.Y;
    }
    cout << ans;
}