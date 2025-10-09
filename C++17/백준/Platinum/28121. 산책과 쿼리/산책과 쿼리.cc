#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;
// 로직 수정에 gpt 활용함
int p[300001], dist[300001]={}, siz[300001];
bool vis[300001]={};
int getp(int a) {
    if (p[a]==a) return a;
    int tp=p[a];
    p[a] = getp(p[a]);
    dist[a] += dist[tp];
    dist[a] %= 2;
    return p[a];
}
void Union(int a, int b) {
    int pa = getp(a), pb = getp(b);
    if (pa==pb) return;
    if (pa<pb) {
        p[pb]=pa;
        dist[pb]=dist[b]+dist[a]+1;
        dist[pb] %= 2;
        siz[pa] += siz[pb];
    }
    else {
        p[pa]=pb;
        dist[pa]=dist[a]+dist[b]+1;
        dist[pa] %= 2;
        siz[pb] += siz[pa];
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {p[i]=i; siz[i]=1;}
    int ans=0;
    while (m--) {
        int a, b, pa, pb;
        cin >> a >> b;
        pa = getp(a), pb=getp(b);
        if (vis[pa]&&vis[pb]) {cout << ans << '\n'; continue;}
        else if (vis[pa]) {
            ans += siz[pb];
            vis[pb]=1;
        }
        else if (vis[pb]) {
            ans += siz[pa];
            vis[pa]=1;
        }
        else if (pa==pb && (dist[a]+dist[b])%2==0) {
            Union(a,b);
            int gp=min(getp(a),getp(b));
            ans += siz[gp];
            vis[gp]=1;
        } 
        Union(a,b);
        cout << ans << '\n';
    }
}   