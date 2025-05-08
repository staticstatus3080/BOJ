#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

ll sum[400001]={}, leftmax[400001]={}, rightmax[400001]={}, ans[400001]={}, output=0;

struct p {
    ll l, r, s, m;
};

void Update(ll idx, ll st, ll en, ll cur, ll diff) {
    sum[idx] += diff;
    if (st==en) {
        ans[idx] = leftmax[idx] = rightmax[idx] = sum[idx];
        return;
    }
    ll mid = (st+en)/2;
    if (cur<=mid) Update(idx*2, st, mid, cur, diff);
    else Update(idx*2+1, mid+1, en, cur, diff);
    leftmax[idx] = max(leftmax[idx*2], sum[idx*2]+leftmax[idx*2+1]);
    rightmax[idx] = max(rightmax[idx*2+1], sum[idx*2+1]+rightmax[idx*2]);
    ans[idx] = max(max(ans[idx*2], ans[idx*2+1]), rightmax[idx*2]+leftmax[idx*2+1]);
}

p Query(ll idx, ll st, ll en, ll l, ll r) {
    if (r<st || en<l) {
        p tmp = {(ll)-1e10, (ll)-1e10, (ll)-1e10, (ll)-1e10};
        return tmp;
    }
    if (l<=st && en<=r) {
        p tmp = {leftmax[idx], rightmax[idx], sum[idx], ans[idx]};
        return tmp;
    }
    ll mid = (st+en)/2;
    p p1 = Query(idx*2, st, mid, l, r);
    p p2 = Query(idx*2+1, mid+1, en, l, r);
    p ret;
    ret.l = max(p1.l, p1.s+p2.l);
    ret.r = max(p2.r, p2.s+p1.r);
    ret.s = p1.s+p2.s;
    ret.m = max(max(p1.m, p2.m), p1.r+p2.l);
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i=1; i<=n; i++) {
        ll a;
        cin >> a;
        Update(1, 1, n, i, a);
    }

    ll q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        p ret = Query(1, 1, n, a, b);
        cout << ret.m << '\n';
    }
}