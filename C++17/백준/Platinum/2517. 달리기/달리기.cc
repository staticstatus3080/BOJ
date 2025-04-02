#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

// val : 좌압 전->후
int val[500001], cnt[500001], tree[2000001]={};
vector<int> v;

void Update(int idx, int st, int en, int cur, int val) {
    if (cur<st || en<cur) return;
    if (st==en) {
        tree[idx] = val;
        return;
    }
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur, val);
    Update(idx*2+1, mid+1, en, cur, val);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

int Query(int idx, int st, int en, int l, int r) {
    if (l>r) return 0;
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
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> val[i];
        v.push_back(val[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int siz = 500000;
    for (int i=1; i<=n; i++) {
        val[i] = lower_bound(v.begin(), v.end(), val[i]) - v.begin()+1;
        cnt[val[i]]++;
        cout << (i-Query(1, 1, siz, 1, val[i]-1)) << '\n';
        Update(1, 1, siz, val[i], cnt[val[i]]);
    }
}