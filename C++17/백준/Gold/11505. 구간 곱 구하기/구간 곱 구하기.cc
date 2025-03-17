#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define MOD 1000000007
using namespace std;
// https://book.acmicpc.net/ds/segment-tree 참고하였습니다.
vector<ll> tree(3000001), arr(1500001); 


void Init(int node, int start, int end) {
    if (start==end) {
        tree[node] = arr[start];
    }
    else {
        Init(node*2, start, (start+end)/2);
        Init(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2]*tree[node*2+1]%MOD;
    }
}

void Update(int node, int start, int end, int index, ll val) {
    if (index<start || end<index) return;
    if (start == end) {
        tree[node] = val;
        return;
    }
    Update(node*2, start, (start+end)/2, index, val);
    Update(node*2+1, (start+end)/2+1, end, index, val);
    tree[node] = tree[node*2]*tree[node*2+1]%MOD;
}

ll Query(int node, int start, int end, int left, int right) {
    if (left>end || right<start) return 1;
    if (left<=start && end<=right) return tree[node];
    ll lval = Query(node*2, start, (start+end)/2, left, right);
    ll rval = Query(node*2+1, (start+end)/2+1, end, left, right);
    return lval*rval%MOD;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    Init(1, 0, n-1);
    for (int i=0; i<m+k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1) Update(1, 0, n-1, b-1, c);
        else cout << Query(1, 0, n-1, b-1, c-1) << '\n';
    }

}