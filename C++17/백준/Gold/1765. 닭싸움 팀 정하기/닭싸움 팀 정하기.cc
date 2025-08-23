#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int p[100001];
bool vis[1001]={};
vector<int> adj[1001];
int getp(int a) {
    if (p[a]==a) return a;
    else return p[a] = getp(p[a]);
}
void Union(int a, int b) {
    a = getp(a); b = getp(b);
    if (a>b) swap(a,b);
    p[b]=a;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v, v1;
    for (int i=1; i<=n; i++) p[i]=i;
    while (m--) {
        char c; int a, b;
        cin >> c >> a >> b;
        if (c=='E') {
            v.push_back({a,b});
        }
        else {
            v1.push_back({a,b});
        }
    }
    for (auto cur : v) {
        auto [a,b] = cur;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        int tmp = i;
        if (vis[tmp]) continue;
        vis[tmp]=1;
        int parity[3]={};
        parity[1]=tmp;
        queue<pair<int,int>> q;
        q.push({tmp,1});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto nxt : adj[cur.X]) {
                if (vis[nxt]) continue;
                vis[nxt]=1;
                int nxtparity = 3-cur.Y;
                if (parity[nxtparity]==0) parity[nxtparity]=nxt;
                else Union(nxt, parity[nxtparity]);
                q.push({nxt, nxtparity});
            }
        }
    }
    for (auto cur : v1) {
        auto [a,b] = cur;
        Union(a,b);
    }
    memset(vis, 0, sizeof(vis));
    int ans=0;
    for (int i=1; i<=n; i++) {
        int tmp = getp(i);
        if (vis[tmp]) continue;
        ans++;
        vis[tmp]=1;
    }    
    cout << ans;
}   