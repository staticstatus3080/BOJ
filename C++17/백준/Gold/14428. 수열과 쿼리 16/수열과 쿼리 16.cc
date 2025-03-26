#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define INF 1e9+1
using namespace std;

int tree[400001]={}, arr[100001];

void Init(int idx, int st, int en) {
    if (st==en) {
        tree[idx] = st;
        return;
    }
    int mid=(st+en)/2;
    Init(idx*2, st, mid);
    Init(idx*2+1, mid+1, en);
    if (arr[tree[idx*2]]<=arr[tree[idx*2+1]]) tree[idx] = tree[idx*2];
    else tree[idx] = tree[idx*2+1];
}
// 인덱스 처리
void Update(int idx, int st, int en, int cur, int val) {
    if (st==en) {
        tree[idx] = cur;
        return;
    } 
    int mid = (st+en)/2;
    if (cur<=mid) Update(idx*2, st, mid, cur, val);
    else Update(idx*2+1, mid+1, en, cur, val);
    if (arr[tree[idx*2]]<=arr[tree[idx*2+1]]) tree[idx] = tree[idx*2];
    else tree[idx] = tree[idx*2+1];

}
// 최솟값의 인덱스 출력
int Query(int idx, int st, int en, int l, int r) {
    if (r<st || en<l) return 0;
    if (l<=st && en<=r) return tree[idx];
    int mid = (st+en)/2;
    int lq = Query(idx*2, st, mid, l, r);
    int rq = Query(idx*2+1, mid+1, en, l, r);
    if (arr[lq]<=arr[rq]) return lq;
    else return rq;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q, a, b, c;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    arr[0] = INF;
    Init(1, 1, n);
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> c;
        if (c==1) {
            cin >> a >> b;
            arr[a] = b;
            Update(1, 1, n, a, b);
        }
        if (c==2) {
            cin >> a >> b;
            int ret = Query(1, 1, n, a, b); 
            cout << ret << '\n';
        }
    }
}