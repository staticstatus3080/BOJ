#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

ll N, M, C[201010];
bool vis[202020]={}, flag=0;
vector<int> G[201010], R[201010], V;
vector<vector<int>> S;
void AddEdge(int s, int e) {
    if (s<0) s = -s+100000;
    if (e<0) e = -e+100000;
    G[s].push_back(e);
    R[e].push_back(s);
}
void DFS1(int v) {
    C[v] = -1;
    for (auto i : G[v]) if (!C[i]) DFS1(i);
    V.push_back(v);
}
void DFS2(int v, int c){
    C[v] = c; S.back().push_back(v);
    for (auto i : R[v]) if(C[i]== -1) DFS2(i, c);
}
int GetSCC() {
    for (int i=1; i<=N; i++) if (!C[i]) DFS1(i);
    reverse(V.begin(), V.end());
    int cnt=0;
    for (auto i : V) if (C[i] == -1) S.emplace_back(), DFS2(i, ++cnt);
    return cnt;
}

void Solve(int v) {
    vis[v]=1;
    for (auto i : G[v]) {
        if (vis[i]) continue;
        Solve(i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while (cin >> N >> M) {
        V.clear();
        S.clear();
        memset(C, 0, sizeof(C));
        memset(vis, 0, sizeof(vis));
        flag=0;
        for (int i=0; i<M; i++) {
            int a, b;
            cin >> a >> b;
            AddEdge(-a, b);
            AddEdge(-b, a);
        }
        int K = GetSCC();
        for (auto &vec : S) sort(vec.begin(), vec.end());
        sort(S.begin(), S.end());
        for (auto &vec : S) {
            memset(vis, 0, sizeof(vis));
            for (auto i : vec) {
                int tmp = (i>100000) ? i-100000 : i+100000;
                if (vis[tmp]) {
                    flag=1;
                    break;
                }
                vis[i]=1;
            } 
            if (flag) break;
        }
        if (flag) {
            cout << "no\n";
            for (int i=1; i<=N; i++) {G[i].clear(); G[i+100000].clear(); R[i].clear(); R[i+100000].clear();}
            continue;   
        }
        memset(vis, 0, sizeof(vis));
        Solve(1);
        for (int i=1; i<=N; i++) {
            if (vis[i] && vis[i+100000]) flag=1;
        }
        if (!flag) cout << "yes\n";
        else cout << "no\n";
        for (int i=1; i<=N; i++) {G[i].clear(); G[i+100000].clear(); R[i].clear(); R[i+100000].clear();}
        }
}
