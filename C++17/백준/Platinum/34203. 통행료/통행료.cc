#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii> e;
vector<int> ans;
int dist[502][502];
int n, m, p[501];

int Getp(int a) {
    if (p[a]==a) return a;
    else return p[a]=Getp(p[a]);
}
void Union(int a, int b) {
    a = Getp(a);
    b = Getp(b);
    if (a>b) p[a]=b;
    else p[b]=a;
}
int Calc() {
    int ret=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ret += dist[i][j];
        }
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        e.push_back({a,b});
        dist[a][b] = dist[b][a]=1;
    }
    for (int i=1; i<=n; i++) {dist[i][i]=0; p[i]=i;}
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    reverse(e.begin(), e.end());
    int ret = Calc();
    for (auto cur : e) {
        ans.push_back(ret);
        auto [a,b] = cur;
        if (Getp(a)==Getp(b)) {
            continue;
        }
        Union(a,b);
        dist[a][b] = dist[b][a]=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(min(dist[i][j], dist[i][a]+dist[b][j]), dist[i][b]+dist[a][j]);
            }
        }
        ret = Calc();
    }
    reverse(ans.begin(), ans.end());
    for (auto cur : ans) cout << cur << '\n';
}