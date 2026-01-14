#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std; 

const int MAX = 500005;
vector<int> gph[MAX];
bool vis[MAX]={};
int in[MAX], low[MAX], piv;
vector<int> ans;

void dfs(int x, int p =-1) {
    in[x] = ++piv;
    low[x] = 1e9;
    vis[x]=1;
    int child = 0;
    bool cut = false;
    for (auto &y : gph[x]) {
        if (y==p) continue;
        if (!in[y]) {
            dfs(y, x);
            if (low[y] >= in[x]) cut = true;
            low[x] = min(low[x], low[y]);
            child++;
        }
        else if (in[y] < in[x]) {
            low[x] = min(low[x], in[y]);
        }
    }

    if (p!=-1 && cut)
        ans.push_back(x);
    // 루트 예외처리
    if (p==-1 && child>=2)
        ans.push_back(x);
}
set<pii> s;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (b>a) swap(a,b);
        if (s.find({a,b})!=s.end()) {
            continue;
        }
        gph[a].push_back(b);
        gph[b].push_back(a);
        s.insert({a,b});
    }
    for (int i=0; i<n; i++) {
        if (!vis[i]) dfs(i);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (auto cur : ans) {
        cout << cur << ' ';
    }
}
