#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;


int tree[8000001]={}, arr[2000001]={};


void Init(int idx, int st, int en) {
    if (st==en) {
        tree[idx] = 1;
        return;
    }
    int mid = (st+en)/2;
    Init(idx*2, st, mid);
    Init(idx*2+1, mid+1, en);
    tree[idx] = tree[idx*2]+tree[idx*2+1];
}

void Update(int idx, int st, int en, int cur, int diff) {
    if (cur<st||en<cur) return;
    tree[idx] += diff;
    if (st==en) return;
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur, diff);
    Update(idx*2+1, mid+1, en, cur, diff);
}

int Query(int idx, int st, int en, int val) {
    if (st==en) return st;
    int mid = (st+en)/2;
    if (tree[idx*2]<val) {
        return Query(idx*2+1, mid+1, en, val-tree[idx*2]);
    }
    else return Query(idx*2, st, mid, val);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) arr[i] = 1;
    Init(1, 1, n);
    vector<int> v;
    int cnt = k;
    for (int i=1; i<=n; i++) {
        int siz = n-i+1;
        while (cnt>siz) cnt -= siz;
        int ans = Query(1, 1, n, cnt); 
        v.push_back(ans);
        Update(1, 1, n, ans, -1);
        cnt += (k-1);
    }
    cout << '<';
    for (int i=0; i<v.size()-1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << '>';
}