#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int arr[1000001], tree[4000001];

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

int Query(int idx, int st, int en, int k) {
    if (k<=arr[st]) {Update(1, 1, 1000000, st, -1); arr[st]--; return st;}
    int lsum = tree[idx*2], rsum = tree[idx*2+1];
    int mid = (st+en)/2;
    if (lsum<k) return Query(idx*2+1, mid+1, en, k-lsum);
    return Query(idx*2, st, mid, k);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    Init(1, 1, 1000000);
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        if (a==2) {
            int b, c;
            cin >> b >> c;
            arr[b]+=c;
            Update(1, 1, 1000000, b, c);
        }
        else {
            int k;
            cin >> k;
            cout << Query(1, 1, 1000000, k) << '\n';
        }
    }
}   