#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define INF 1e9+1
using namespace std;

int p[10001] = {};
bool vis[10001] = {};
int Up(int k) {
    if (vis[k]) {
        return k;
    }
    vis[k] = true;
    if (p[k]!=0) return Up(p[k]);
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        memset(p, 0, sizeof(p));
        memset(vis, 0, sizeof(vis));
        int n;
        cin >> n;
        for (int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            p[b] = a;
        }
        int a, b;
        cin >> a >> b;
        Up(a);
        cout << Up(b) << '\n';
    }
}