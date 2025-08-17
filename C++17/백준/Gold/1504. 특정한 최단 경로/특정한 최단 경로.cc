#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, e, dist[801][801];
vector<pair<int, int>> graph[801];

void getDist(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (dist[st][cur.Y] != cur.X) continue;
        for (auto nxt : graph[cur.Y]) {
            if (dist[st][nxt.Y] <= dist[st][cur.Y] + nxt.X) continue;
            dist[st][nxt.Y] = dist[st][cur.Y] + nxt.X;
            pq.push({dist[st][nxt.Y], nxt.Y});
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    cin >> n >> e;
    for (int i=1; i<=n; i++) {
        fill(dist[i], dist[i]+n+1, 1e9);
        dist[i][i] = 0;
    }
    
    for (int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    int a, b;
    cin >> a >> b;
    
    getDist(1);
    getDist(a);
    getDist(b);
    
    int ans = min(dist[1][a] + dist[a][b] + dist[b][n], dist[1][b] + dist[b][a] + dist[a][n]);
    if (dist[1][a] == 1e9 || dist[a][b] == 1e9 || dist[b][n] == 1e9) cout << -1;
    else cout << ans;
}
