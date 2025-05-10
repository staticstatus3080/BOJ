#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

ll sum[12001]={}, leftmax[12001]={}, rightmax[12001]={}, ans[12001]={};
vector<ll> xpos, cx, ypos, cy, val;
struct p {
    ll l, r, s, m;
};
struct pos {
    ll x, y, val;
};
vector<pos> point; 

bool cmp(pos p1, pos p2) {
    if (p1.x==p2.x) return p1.y<p2.y;
    return p1.x<p2.x;
}

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
        p tmp = {(ll)-1e15, (ll)-1e15, (ll)-1e15, (ll)-1e15};
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
    for (int i=0; i<n; i++) {
        ll x, y, a;
        cin >> x >> y >> a;
        xpos.push_back(x);
        ypos.push_back(y);
        pos tmp = {x, y, a};
        point.push_back(tmp);
    }
    sort(xpos.begin(), xpos.end());
    sort(ypos.begin(), ypos.end());
    ll maxx=0;
    for (int i=0; i<n; i++) {
        point[i].x = lower_bound(xpos.begin(), xpos.end(), point[i].x) - xpos.begin();
        point[i].y = lower_bound(ypos.begin(), ypos.end(), point[i].y) - ypos.begin();
        maxx = max(maxx, point[i].x);
    }
    sort(point.begin(), point.end(), cmp);
    ll output = 0;
    for (int i=0; i<=maxx; i++) {
        int idx=0, preX=0;
        memset(sum, 0, sizeof(sum));
        memset(leftmax, 0, sizeof(leftmax));
        memset(rightmax, 0, sizeof(rightmax));
        memset(ans, 0, sizeof(ans));
        for (auto cur : point) {
            if (cur.x<i) continue;
            if (cur.x!=preX) {output = max(output, Query(1, 0, n-1, 0, n-1).m); preX = cur.x;}
            Update(1, 0, n-1, cur.y, cur.val);
        }
        output = max(output, Query(1, 0, n-1, 0, n-1).m);
    }
    cout << output;
}