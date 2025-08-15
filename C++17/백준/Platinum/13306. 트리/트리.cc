#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;

int p[200001], up[200001];

int getp(int a) {
    if (p[a]==a) return a;
    else return p[a] = getp(p[a]); 
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    p[1]=up[1]=1;
    for (int i=2; i<=n; i++) {
        cin >> up[i];
        p[i]=i;
    }
    vector<pii> v;
    q += n-1;
    while (q--) {
        int a;
        cin >> a;
        if (a==1) {
            int b, c;
            cin >> b >> c;
            v.push_back({b,c});
        }
        else {
            int a;
            cin >> a;
            v.push_back({a,0});
        }
    }
    reverse(v.begin(), v.end());
    vector<bool> ans;
    for (auto cur : v) {
        if (cur.Y==0) {
            p[cur.X] = up[cur.X];
        }
        else {
            int a = getp(cur.X), b = getp(cur.Y);
            ans.push_back(a==b);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto cur : ans) {
        if (cur) cout << "YES\n";
        else cout << "NO\n";
    }
}   