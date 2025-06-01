#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
// https://stonejjun.tistory.com/84을 참고하였습니다
using namespace std;

vector<int> adj[10001], scc[10001];
vector<pair<int, int>> edge;
bool vis[10001]={};
stack<int> s;
void DFS(int cur) {
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt]=1;
        DFS(nxt);
    }
    s.push(cur);
}

void SCC(int cur, int idx) {
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt]=1;
        scc[idx].push_back(nxt);
        SCC(nxt, idx);
    }
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int a,b;
        cin >> a >> b;
        edge.push_back({a,b});
        adj[a].push_back(b);
    }
    for (int i=1; i<=v; i++) {
        if (!vis[i]) {
            vis[i]=1;
            s.push(i);
            DFS(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=v; i++) adj[i].clear();
    for (auto cur : edge) {
        adj[cur.Y].push_back(cur.X);
    }
    int cnt=0;
    while (!s.empty()) {
        auto cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        scc[cnt].push_back(cur);
        vis[cur]=1;
        SCC(cur, cnt);
        cnt++;
    }
    cout << cnt << '\n';
    for (int i=0; i<cnt; i++) {
        sort(scc[i].begin(), scc[i].end());
    }
    sort(scc, scc+cnt);
    for (int i=0; i<cnt; i++) {
        for (auto cur : scc[i]) cout << cur << ' ';
        cout << -1 << '\n';
    }
}