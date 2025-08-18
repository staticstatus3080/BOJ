#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int arr[1000001], tree[4000001]={};

void Init(int idx, int st, int en) {
    if (st==en) {
        tree[idx] = 0;
        return;
    }
    int mid = (st+en)/2;
    Init(idx*2, st, mid);
    Init(idx*2+1, mid+1, en);
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
    int mid = (st+en)/2;
    return Query(idx*2, st, mid, l, r) + Query(idx*2+1, mid+1, en, l, r);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    ll ans=0;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        ans += Query(1, 1, n, a+1, n);
        arr[a]++;
        Update(1, 1, n, a, 1);
    }
    cout << ans;
}   