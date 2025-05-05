#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define MOD (int)1e9+7
using namespace std;

int n;
int tree[1600001]={};
vector<pair<int, int>> pos;


void Update(int idx, int st, int en, int cur, int diff) {
    if (cur<st || en<cur) return;
    tree[idx] += diff;
    if (st==en) return;
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur, diff);
    Update(idx*2+1, mid+1, en, cur, diff);
}

ll Query(int idx, int st, int en, int l, int r) {
    if (r<st || en<l) return 0;
    if (l<=st && en<=r) return tree[idx];
    ll ret=0;
    int mid = (st+en)/2;
    ret += Query(idx*2, st, mid, l, r);
    ret += Query(idx*2+1, mid+1, en, l, r);
    return ret;
}

bool cmp(pair<int, int> a, pair<int,int> b) {
    if (a.Y==b.Y) {
        return a.X<b.X;
    }
    return a.Y>b.Y;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back({x+200000, y+200000});
    }
    sort(pos.begin(), pos.end(), cmp);
    // 범위 : 0~400000
    // 유사 lazy?
    queue<int> q;
    int lastY=-1;
    ll ans=0;
    for (auto cur : pos) {
        int curX = cur.X, curY = cur.Y;
        if (lastY!=curY) {
            lastY = curY;
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                Update(1, 0, 400000, a, 1);
            }
        }
        ll tmp=1;
        tmp *= Query(1, 0, 400000, 0, curX-1);
        tmp *= Query(1, 0, 400000, curX+1, 400000);
        ans += tmp;
        ans %= MOD;
        q.push(curX);
    }
    cout << ans;
}