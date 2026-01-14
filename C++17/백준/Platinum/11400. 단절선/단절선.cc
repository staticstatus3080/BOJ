#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std; 

const int MAX = 200005;
vector<int> gph[MAX];
bool vis[MAX]={};
int in[MAX], low[MAX], piv;
vector<pii> cut_edges;

void dfs(int x, int p =-1) {
    in[x] = ++piv;
    low[x] = 1e9;
    vis[x]=1;
    for (auto &y : gph[x]) {
        if (y==p) continue;
        if (!in[y]) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
        }
        else if (in[y] < in[x]) {
            low[x] = min(low[x], in[y]);
        }
    }
    if (p!=-1 && low[x] >= in[x]) {
        cut_edges.push_back({p,x});
    }
}
set<pii> s, multi;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (a==b) continue;
        if (a>b) swap(a,b);
        if (s.find({a,b})!=s.end()) {
            multi.insert({a,b});
            continue;
        }
        gph[a].push_back(b);
        gph[b].push_back(a);
        s.insert({a,b});
    }
    for (int i=0; i<n; i++) {
        if (!vis[i]) dfs(i);
    }
    vector<pii> ans;
    for (auto cur : cut_edges) {
        if (cur.X>cur.Y) swap(cur.X, cur.Y);
        if (multi.find(cur)==multi.end()) ans.push_back(cur);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur.X << ' ' << cur.Y << '\n';
    }
}