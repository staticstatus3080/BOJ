#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

vector<pii> adj[10001]; // 비용, 정점
ll n, m, k, d[10001][21];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a}); 
    }
    memset(d, 0x2f, sizeof(d));
    d[1][0]=0;
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    // 포장 횟수, 비용, 번호
    pq.push({0,0,1});
    while (!pq.empty()) {
        auto [pave, cost, cur] = pq.top();
        pq.pop();
        if (cost > d[cur][pave]) continue;
        for (auto e : adj[cur]) {
            if (d[e.Y][pave] > d[cur][pave]+e.X) {
                d[e.Y][pave] = d[cur][pave]+e.X;
                pq.push({pave, d[e.Y][pave], e.Y});
            }
            if (pave<k && d[e.Y][pave+1]>d[cur][pave]) {
                d[e.Y][pave+1]=d[cur][pave];
                pq.push({pave+1, d[e.Y][pave+1], e.Y});
            }
        }
    }
    ll ans=1e18;
    for (int i=0; i<=k; i++) {
        ans = min(ans, d[n][i]);
    }
    cout << ans;
}