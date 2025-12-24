#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;

vector<pair<int, int>> graph[1001];

int d[1001], dp[1001];

int DFS(int cur) {
    if (dp[cur] != -1) return dp[cur];
    int returnVal=0;
    for (auto nxt : graph[cur]) {
        int nxtNode = nxt.X;
        if (d[cur]<=d[nxtNode] || d[nxtNode]==1e9) continue;
        returnVal += DFS(nxtNode);
    }
    return dp[cur] = returnVal;
}
int main() {  
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    fill(d, d+n+1, 1e9);
    d[2]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 2});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int node = cur.Y, curD = cur.X;
        if (d[node] != curD) continue;
        for (auto nxt : graph[node]) {
            int nxtNode = nxt.X, nxtD = nxt.Y; 
            if (d[nxtNode] <= curD+nxtD) continue;
            d[nxtNode] = curD+nxtD;
            pq.push({d[nxtNode], nxtNode});
        }
    }
    fill(dp, dp+n+1, -1);
    dp[2]=1;
    cout << DFS(1);
}