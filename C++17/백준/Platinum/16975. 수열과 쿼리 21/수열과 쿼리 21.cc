#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

ll tree[400001]={}, arr[100005];

void Update(int idx, int st, int en, int l, int r, ll diff) {
    if (r<st || en<l) return;
    if (l<=st && en<=r) {
        tree[idx] += diff;
        return;
    }
    int mid = (st+en)/2;
    Update(idx*2, st, mid, l, r, diff);
    Update(idx*2+1, mid+1, en, l, r, diff);
}

ll Query(int idx, int st, int en, int pos) {
    if (pos<st || en<pos) return 0;
    ll val=0;
    int mid = (st+en)/2;
    val += tree[idx];
    if (st==en) return val;
    val += Query(idx*2, st, mid, pos);
    val += Query(idx*2+1, mid+1, en, pos);
    return val;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    for (int i=0; i<m; i++) {
        int q;
        cin >> q;
        if (q==1) {
            int a, b, c;
            cin >> a >> b >> c;
            Update(1, 1, n, a, b, c);
        }
        else {
            int a;
            cin >> a;
            cout << arr[a]+Query(1, 1, n, a) << '\n';
        }
    }
}