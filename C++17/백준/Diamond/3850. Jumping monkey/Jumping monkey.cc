#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;
vector<int> adj[21];
queue<pair<int, vector<int>>> q;
bool vis[1<<21]={};
bool isImp=false;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) {
        int n,m;
        cin >> n >> m;
        if (n==0&&m==0) return 0;
        for (int i=0; i<21; i++) adj[i].clear();
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (m!=n-1) {
            cout << "Impossible\n";
            continue;
        }
        while (!q.empty()) q.pop();
        int init = (1<<n)-1;
        vis[init]=1;
        vector<int> initV={};
        q.push({init, initV});
        bool flag = false;
        while (!q.empty()) {
            auto curP = q.front();
            auto cur = curP.X;
            if (cur==0) {
                auto ans = curP.Y;
                cout << ans.size() << ": ";
                for (auto i : ans) {
                    cout << i << ' ';
                }
                cout << '\n';
                flag = true;
                break;
            }
            q.pop();
            for (int i=0; i<=(n-1); i++) {
                int tmp = cur;
                // i번째 칸에 총을 쏜다
                for (int nxt=0; nxt<=(n-1); nxt++) {
                    bool isDie=true;
                    for (auto e : adj[nxt]) {
                        if (e!=i && ((1<<e)&cur)!=0) {isDie=false; break;}
                    }
                    if (isDie) tmp &= (((1<<n)-1)-(1<<nxt));
                    else tmp |= (1<<nxt);
                }
                if (vis[tmp]) continue;
                vector<int> tmpV = curP.Y;
                tmpV.push_back(i);
                vis[tmp]=1;
                q.push({tmp, tmpV});
            }
        }
        if (!flag) cout << "Impossible\n";
    }
}