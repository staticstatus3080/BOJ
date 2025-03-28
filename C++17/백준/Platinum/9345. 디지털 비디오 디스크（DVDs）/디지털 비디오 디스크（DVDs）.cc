#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;


int maxtree[400001], mintree[400001], arr[100002];
void Init(int idx, int st, int en) {
    if (st==en) {
        maxtree[idx] = mintree[idx] = arr[st];
        return;
    }
    int mid = (st+en)/2;
    Init(idx*2, st, mid);
    Init(idx*2+1, mid+1, en);
    maxtree[idx] = max(maxtree[idx*2], maxtree[idx*2+1]);
    mintree[idx] = min(mintree[idx*2], mintree[idx*2+1]);
}

int minquery(int idx, int left, int right, int st, int en) {
    if (right<st || en<left) return 1e9;
    if (st<=left && right<=en) return mintree[idx];
    int returnVal = minquery(idx*2, left, (left+right)/2, st, en);
    returnVal = min(returnVal, minquery(idx*2+1, (left+right)/2+1, right, st, en));
    return returnVal;
}

int maxquery(int idx, int left, int right, int st, int en) {
    if (right<st || en<left) return 0;
    if (st<=left && right<=en) return maxtree[idx];
    int returnVal = maxquery(idx*2, left, (left+right)/2, st, en);
    returnVal = max(returnVal, maxquery(idx*2+1, (left+right)/2+1, right, st, en));
    return returnVal;
}

void Update(int idx, int st, int en, int cur, int val) {
    if (cur<st || en<cur) return;
    if (st==en) {
        maxtree[idx] = mintree[idx] = val;
        return;
    }
    Update(idx*2, st, (st+en)/2, cur, val);
    Update(idx*2+1, (st+en)/2+1, en, cur, val);
    maxtree[idx] = max(maxtree[idx*2], maxtree[idx*2+1]);
    mintree[idx] = min(mintree[idx*2], mintree[idx*2+1]);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++) arr[i] = i;
        Init(1, 0, n-1);
        for (int i=0; i<m; i++) {
            int q, a, b;
            cin >> q >> a >> b;
            if (q==0) {
                swap(arr[a], arr[b]);
                Update(1, 0, n-1, a, arr[a]);
                Update(1, 0, n-1, b, arr[b]);
            }
            else {
                int minn = minquery(1, 0, n-1, a, b);
                int maxx = maxquery(1, 0, n-1, a, b);
                if (minn!=a || maxx != b) cout << "NO";
                else cout << "YES";
                cout << '\n';
            }
        }
    }
}