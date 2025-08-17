#include <bits/stdc++.h>
// 재풀이 : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1D/solutions/1753.cpp 참고
using namespace std;

vector<pair<int, int>> graph[20001]; // 비용, 정점 번호
int V, E, K, d[20001], fix[20001] = {};

void dijkstra() {
    fill(d, d+V+1, INT_MAX);
    d[K] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
    
    pq.push({0, K});
    while (!pq.empty()) {
        int len = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if (d[idx] != len) continue; // 중간에 비용 갱신됨
        
        for (auto e : graph[idx]) {
            if (d[e.second] <= d[idx]+e.first) continue;
            d[e.second] = d[idx]+e.first;
            pq.push({d[e.second], e.second});
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    cin >> V >> E >> K;
    for (int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    
    dijkstra();
    for (int i=1; i<=V; i++) {
        if (d[i] == INT_MAX) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}