#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;

int board[101][101]={}, team[101][101]={}, tmpDist[10001], bound[10001]={}, ans=1e9, idx=0, n, m;
bool vis[101][101]={}, visNode[10001];
set<int> adj[10001];
queue<pair<int, int>> q;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void DFS(int x, int y, int val) {
    if (x<0 || y<0 || x>=n || y>=m) return;
    if (vis[x][y]) return;
    if (board[x][y]!=val) return;
    vis[x][y]=1;
    team[x][y]=idx;
    for (int i=0; i<4; i++) {
        DFS(x+dx[i], y+dy[i], board[x][y]);
    }
}

void Push(int nxt, int d) {
    if (visNode[nxt]) return;
    visNode[nxt]=1;
    tmpDist[nxt] = d;
    q.push({nxt,d});
}
void BFS(int a) {
    int maxDist=0;
    memset(tmpDist, -1, sizeof(tmpDist));
    Push(a,0);
    while (!q.empty()) {
        auto [cur,d] = q.front();
        q.pop();
        for (auto nxt : adj[cur]) {
            Push(nxt,d+1);
            maxDist = max(maxDist, tmpDist[nxt]);
        }
    }
    ans = min(ans, maxDist);
    for (int i=1; i<=idx; i++) {
        bound[i] = max(bound[i], max(tmpDist[i], maxDist-tmpDist[i]));
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (vis[i][j]) continue;
            team[i][j] = ++idx;
            DFS(i, j, board[i][j]);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a = team[i][j], b = team[i+1][j];
            if (i!=(n-1)&&a!=b) {
                adj[a].insert(b);
                adj[b].insert(a);
            }
            a = team[i][j], b = team[i][j+1];
            if (j!=(m-1)&&a!=b) {
                adj[a].insert(b);
                adj[b].insert(a);
            }
        }
    }
    // 정점은 1~idx까지
    for (int i=1; i<=idx; i++) {
        if (bound[i]>=ans) continue;
        memset(visNode, 0, sizeof(visNode));
        BFS(i);
    }
    cout << ans;
}