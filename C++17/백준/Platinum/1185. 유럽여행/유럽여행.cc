#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

// MST 구성: 자신+상대+간선비용으로 새로운 간선 만듦
int ncost[10001]={}, tmp=1e9;
bool vis[10001]={};
vector<pii> v[10001];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, p;
    cin >> n >> p;
    for (int i=1; i<=n; i++) {cin >> ncost[i]; tmp = min(tmp, ncost[i]);}
    for (int i=0; i<p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        c= ncost[a]+ncost[b]+2*c;
        v[a].push_back({-c, b});
        v[b].push_back({-c, a});
    }
    priority_queue<pii> pq;
    pq.push({0,1});
    ll ans=0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (vis[cur.Y]) continue;
        vis[cur.Y]=1;
        ans += -cur.X;
        for (auto nxt : v[cur.Y]) {
            if(vis[nxt.Y]) continue;
            pq.push({nxt});
        }
    }
    cout << ans+tmp;
}    