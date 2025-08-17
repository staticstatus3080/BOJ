#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> graph[2001];
int dist[3][2001];

void dijkstra(int num, int p) {
    dist[p][num] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, num});
    while (!pq.empty()) {
        auto cur = pq.top();
        int curDist = -1 * cur.first;
        int curNum = cur.second;
        pq.pop();
        if (curDist != dist[p][curNum]) continue; // 갱신됨
        for (auto adj : graph[curNum]) {
            int adjDist = adj.first;
            int adjNum = adj.second;
            if (dist[p][adjNum] <= dist[p][curNum] + adjDist) continue;
            dist[p][adjNum] = dist[p][curNum] + adjDist;
            pq.push({-1 * dist[p][adjNum], adjNum});
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {  
        int n, m, t;
        cin >> n >> m >> t;
        int s, g, h;
        cin >> s >> g >> h;
        
        // 초기화 
        for (int i=1; i<=n; i++) {
            graph[i].clear();
        }
        for (int i=0; i<3; i++) {
            fill(dist[i], dist[i]+n+1, 1e9);
        }
        
        // 그래프 채우기
        int must; // g와 h 사이 간선
        for (int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if ((a == g && b == h) || (a == h && b == g)) must = c;
            graph[a].push_back({c, b});
            graph[b].push_back({c, a});
        }
        // 다익스트라
        dijkstra(s, 0);
        dijkstra(g, 1);
        dijkstra(h, 2);
        
        vector<int> possible;
        for (int i=0; i<t; i++) {
            int input;
            cin >> input;
            possible.push_back(input);
        }
        
        sort(possible.begin(), possible.end());
        
        // 후보 판정
        // case 1 : s -> h - must > g -> t == s -> t
        // case 2 : s -> g - must > h -> t == s -> t
        for (int cur : possible) {
            if (dist[0][cur] == dist[0][g] + must + dist[2][cur]
               || dist[0][cur] == dist[0][h] + must + dist[1][cur]) {
                cout << cur << ' ';
            }
        }
        cout << '\n';
    }
}