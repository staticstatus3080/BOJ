#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int, int>> adj[1001]; // 비용, 정점
int pre[1001], dist[1001];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    fill(&dist[0], &dist[1001], -1);
    
    priority_queue<pair<int, int>> pq;
    int st, en;
    cin >> st >> en;
    dist[st] = 0; pre[st] = -1;
    pq.push({0, st});
    while (!pq.empty()) {
        int d = pq.top().X, cur = pq.top().Y;
        pq.pop();
        if (d != dist[cur]) continue; // 중간에 비용 갱신
        for (auto nxt : adj[cur]) {
            int nxtNode = nxt.X, nxtDist = nxt.Y;
            if (dist[nxtNode] == -1 || dist[nxtNode] > dist[cur]+nxtDist) {
                dist[nxtNode] = dist[cur]+nxtDist;
                pre[nxtNode] = cur;
                pq.push({dist[nxtNode], nxtNode});
            }
        }
    }
    
    cout << dist[en] << '\n';
    
    vector<int> route;
    int tmp = en;
    while (tmp != -1) {
        route.push_back(tmp);
        tmp = pre[tmp];
    }
    cout << route.size() << '\n';
    for (auto it = route.rbegin(); it != route.rend(); it++) {
        cout << *it << ' ';
    }
}