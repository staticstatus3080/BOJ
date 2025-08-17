#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    long long V, E, dist[401][401];
    cin >> V >> E;
    for (int i=1; i<=V; i++) {
        for (int j=1; j<=V; j++) {
            dist[i][j] = 1e10;
        }
    }
    
    for (int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
 
    for (int i=1; i<=V; i++) {
        for (int j=1; j<=V; j++) {
            for (int k=1; k<=V; k++) {
                if (dist[i][k] == 1e10 || dist[k][j] == 1e10) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    long long minn = 1e10;
    for (int i=1; i<=V; i++) {
        for (int j=1; j<=V; j++) {
            if (dist[i][j] == 1e10 || dist[j][i] == 1e10) continue;
            minn = min(minn, dist[i][j] + dist[j][i]);
        }
    }
    if (minn == 1e10) cout << -1;
    else cout << minn;
}