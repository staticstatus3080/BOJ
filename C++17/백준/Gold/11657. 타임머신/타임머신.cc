#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    long long u[6001], v[6001], w[6001], dist[501];
    bool cycle = false;
    int V, E;
    
    cin >> V >> E;
    for (int i=1; i<=V; i++) {
        dist[i] = 1e10;
    }
    dist[1] = 0;
    for (int i=0; i<E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
    
    for (int i=0; i<V; i++) {
        for (int j=0; j<E; j++) {
            if (dist[u[j]] == 1e10) continue;
            if (dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
                if (i == V-1) cycle = true;
            }
        }
    }
    
    if (cycle) {cout << -1; return 0;}
    for (int i=2; i<=V; i++) {
        if (dist[i] == 1e10) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}
