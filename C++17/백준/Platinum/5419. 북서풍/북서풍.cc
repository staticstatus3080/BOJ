#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;

int tree[300001];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.X == b.X) {
        return a.Y < b.Y;
    }
    return a.X > b.X;
}

void Update(int idx, int st, int en, int cur, int diff) {
    if (cur<st || en<cur) return;
    tree[idx] += diff;
    if (st==en) return;
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur, diff);
    Update(idx*2+1, mid+1, en, cur, diff);
}

int Query(int idx, int st, int en, int l, int r) {
    if (r<st || en<l) return 0;
    if (l<=st && en<=r) return tree[idx];
    int ret=0;
    int mid = (st+en)/2;
    ret += Query(idx*2, st, mid, l, r);
    ret += Query(idx*2+1, mid+1, en, l, r);
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        memset(tree, 0, sizeof(tree));
        vector<pair<int, int>> pos;
        vector<int> x,y;
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            int a,b;
            cin >> a >> b;
            pos.push_back({a,b});
            x.push_back(a);
            y.push_back(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for (int i=0; i<n; i++) {
            int a = pos[i].X, b=pos[i].Y;
            a = lower_bound(x.begin(), x.end(), a) - x.begin();
            b = lower_bound(y.begin(), y.end(), b) - y.begin();
            pos[i] = make_pair(a,b);
        }
        sort(pos.begin(), pos.end(), cmp);
        ll ans=0;
        for (auto cur : pos) {
            int a = cur.X, b = cur.Y;
            ans += Query(1, 0, n-1, 0, b);
            Update(1, 0, n-1, b, 1);
        }
        cout << ans << '\n';
    }
}