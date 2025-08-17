#include <bits/stdc++.h>

using namespace std;

int dist[101][101];
vector<int> route[101][101];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    fill(&dist[1][0], &dist[n][n+1], 1e9);
    for (int i=1; i<=n; i++) dist[i][i] = 0;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
            route[a][b] = {a, b};
        }
    }

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j].clear();
                    for (int e : route[i][k]) {
                        route[i][j].push_back(e);
                    }
                    for (int e : route[k][j]) {
                        route[i][j].push_back(e);
                    }
                    route[i][j].erase(unique(route[i][j].begin(), route[i][j].end()), route[i][j].end());
                }

            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j] == 1e9) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (route[i][j].empty()) cout << 0;
            else {
                cout << route[i][j].size() << ' ';
                for (int e : route[i][j]) cout << e << ' ';
            }
            cout << '\n';
        }
    }
}