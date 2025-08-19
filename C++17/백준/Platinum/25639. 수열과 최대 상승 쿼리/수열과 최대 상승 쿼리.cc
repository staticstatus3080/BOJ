#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int arr[100001], mint[400001], maxt[400001], anst[400001];

void Init(int idx, int st, int en) {
    if (st==en) {
        mint[idx]=maxt[idx]=arr[st];
        anst[idx]=0;
        return;
    }
    int mid = (st+en)/2;
    Init(idx*2, st, mid);
    Init(idx*2+1, mid+1, en);
    mint[idx] = min(mint[idx*2], mint[idx*2+1]);
    maxt[idx] = max(maxt[idx*2], maxt[idx*2+1]);
    anst[idx] = max(anst[idx*2],anst[idx*2+1]);
    anst[idx] = max(anst[idx], maxt[idx*2+1]-mint[idx*2]);
}

void Update(int idx, int st, int en, int cur, int diff) {
    if (cur<st || en<cur) return;
    if (st==en) {
        mint[idx]=maxt[idx]=arr[st];
        return;
    }
    int mid = (st+en)/2;
    Update(idx*2, st, mid, cur, diff);
    Update(idx*2+1, mid+1, en, cur, diff);
    mint[idx] = min(mint[idx*2], mint[idx*2+1]);
    maxt[idx] = max(maxt[idx*2], maxt[idx*2+1]);
    anst[idx] = max(anst[idx*2],anst[idx*2+1]);
    anst[idx] = max(anst[idx], maxt[idx*2+1]-mint[idx*2]);
}

tuple<int,int,int> Query(int idx, int st, int en, int l, int r) {
    if (r<st || en<l) return {1e9+1,-1e9-1,0};
    if (l<=st && en<=r) return {mint[idx],maxt[idx],anst[idx]};
    int mid = (st+en)/2;
    auto [min1,max1,ans1] = Query(idx*2, st, mid, l, r);
    auto [min2,max2,ans2] = Query(idx*2+1, mid+1, en, l, r);
    return {min(min1, min2),max(max1,max2),max(max(ans1,ans2),max2-min1)};
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    Init(1,1,n);
    int q;
    cin >> q;
    while (q--) {
        int a,b,c;
        cin >> a >> b >> c;
        if (a==1) {
            arr[b]=c;
            Update(1,1,n,b,c);
        }
        else {
            auto [w,e,r] = Query(1,1,n,b,c);
            cout << r << '\n';
        }
    }
}   