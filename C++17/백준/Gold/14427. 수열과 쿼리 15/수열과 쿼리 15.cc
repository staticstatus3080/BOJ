#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int arr[100001], tree[400001];

void Init(int idx, int st, int en) {
    if (st==en) {
        tree[idx] = st;
        return;
    }
    int mid = (st+en)/2;
    Init(idx*2, st, mid);
    Init(idx*2+1, mid+1, en);
    if (arr[tree[idx*2]]<=arr[tree[idx*2+1]]) tree[idx] = tree[idx*2];
    else tree[idx] = tree[idx*2+1];
}

void Update(int idx, int st, int en, int cur) {
    if (cur<st || en<cur) return;
    if (st==en) {
        return;
    }
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur);
    Update(idx*2+1, mid+1, en, cur);
    if (arr[tree[idx*2]]<=arr[tree[idx*2+1]]) tree[idx] = tree[idx*2];
    else tree[idx] = tree[idx*2+1];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    Init(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        if (a==1) {
            int b, c;
            cin >> b >> c;
            arr[b]=c;
            Update(1, 1, n, b);
        }
        else {
            cout << tree[1] << '\n';
        }
    }
}   