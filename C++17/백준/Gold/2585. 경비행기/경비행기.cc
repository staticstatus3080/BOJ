#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;
vector<pair<int, int>> pos;
bool vis[1001]={};
int n, k;

double dist(int a, int b, int c, int d) {
    double tmp = (a-b)*(a-b)+(c-d)*(c-d);
    tmp = sqrt(tmp);
    return tmp;
}

bool Try(int fuel) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, pair<int, int>>> q;
    q.push({0,{0, 0}});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (dist(cur.Y.X, 10000, cur.Y.Y, 10000) <= fuel*10) {
            return true;
        }
        if (cur.X>=k) continue;
        for (int i=0; i<n; i++) {
            if (vis[i]) continue;
            if (dist(cur.Y.X, pos[i].X, cur.Y.Y, pos[i].Y) <= fuel*10) {
                vis[i] = true;
                q.push({cur.X+1,{pos[i].X, pos[i].Y}});
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        pos.push_back({a,b});
    }
    int st=1, en=15000, ans=15000;
    while (st<=en) {
        int mid = (st+en)/2;
        if (Try(mid)) {
            ans = mid;
            en = mid-1;
        }
        else {
            st = mid+1;
        }
    }
    cout << ans;
}