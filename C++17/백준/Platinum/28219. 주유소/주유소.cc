#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
// 풀이 참고 ㅠㅠ https://assets.koi.or.kr/koi/2023/1/solutions/2/oil.pdf
using namespace std;

int n, k, ans=0;
vector<int> adj[200001];

int DFS(int cur, int p) {
    int maxdepth=0, premax=0;
    for (auto nxt : adj[cur]) {
        if (nxt==p) continue;
        int nxtInfo = DFS(nxt, cur);
        if (nxtInfo>maxdepth) {
            premax = maxdepth;
            maxdepth = nxtInfo;
        }
        else if (nxtInfo>premax) {
            premax = nxtInfo;
        }
    }
    if (maxdepth+premax>=k) {ans++; return 0;} 
    return maxdepth+1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<(n-1); i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1, -1);
    cout << ans;
}