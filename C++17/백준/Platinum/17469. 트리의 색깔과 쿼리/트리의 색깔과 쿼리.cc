#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;

int p[100001], up[100001];
set<int> s[100001];
int getp(int a) {
    if (p[a]==a) return a;
    else return p[a] = getp(p[a]); 
}

void Union(int a, int b) {
    a = getp(a); b = getp(b);
    if (s[a].size()<s[b].size()) swap(s[a],s[b]);
    for (auto cur : s[b]) s[a].insert(cur);
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
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        s[i].insert(a);
    }
    vector<pii> v;
    q += n-1;
    while (q--) {
        int a;
        cin >> a;
        if (a==1) {
            cin >> a;
            v.push_back({1,a});
        }
        else {
            cin >> a;
            v.push_back({2,a});
        }
    }
    reverse(v.begin(), v.end());
    vector<int> ans;
    for (auto cur : v) {
        if (cur.X==1) {
            Union(up[cur.Y], cur.Y);
            p[cur.Y] = up[cur.Y];
        }
        else {
            ans.push_back(s[getp(cur.Y)].size());
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto cur : ans) cout << cur << '\n';
}   