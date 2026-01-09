#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;
// not K는 10000+K로 표시 
ll N, M, C[20101];
vector<int> G[20101], R[20101], V;
vector<vector<int>> S;
void AddEdge(int s, int e) {
    if (s<0) s = -s+10000;
    if (e<0) e = -e+10000;
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        AddEdge(-a, b);
        AddEdge(-b, a);
    }
    int K = GetSCC();
    reverse(S.begin(), S.end());
    bool vis[20202]={}, flag=0;
    for (auto &vec : S) {
        memset(vis, 0, sizeof(vis));
        for (auto i : vec) {
            int tmp = (i>10000) ? i-10000 : i+10000;
            if (vis[tmp]) {
                flag=1;
                break;
            }
            vis[i]=1;
        } 
        if (flag) break;
    }
    cout << !flag << '\n';
    if (flag) return 0;
    memset(vis, 0, sizeof(vis));
    for (auto &vec : S) {
        bool flag=0;
        for (auto i : vec) {
            if ((i<=10000 && vis[i+10000]) || (i>10000 && vis[i-10000])) flag=1;
        }
        if (flag) continue;
        for (auto i : vec) {
            vis[i]=1;
        }
    }
    for (int i=1; i<=N; i++) {
        if (vis[i]) cout << 1;
        else cout << 0;
        cout << ' ';
    }
}
