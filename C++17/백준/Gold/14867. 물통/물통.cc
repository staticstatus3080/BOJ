#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;

map<pair<int, int>, int> vis;
queue<pair<int, pair<int, int>>> q;

void Push(int a, int b, int c) {
    if (vis[{a,b}]) return;
    vis[{a,b}] = ++c;
    q.push({c,{a,b}});
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c!=0 && c!=a && d!=0 && d!=b) {cout << -1; return 0;}
    if (c==0 && d==0) {cout << 0; return 0;}
    q.push({0, {0, 0}});
    while (!q.empty()) {
        auto cur = q.front();
        if (cur.Y.X==c && cur.Y.Y==d) {
            cout << cur.X;
            return 0;
        }
        q.pop();
        Push(a, cur.Y.Y, cur.X);
        Push(cur.Y.X, b, cur.X);
        Push(0, cur.Y.Y, cur.X);
        Push(cur.Y.X, 0, cur.X);
        if (cur.Y.X<=(b-cur.Y.Y)) Push(0, cur.Y.X+cur.Y.Y, cur.X);
        else Push(cur.Y.X-(b-cur.Y.Y), b, cur.X);
        if (cur.Y.Y<=(a-cur.Y.X)) Push(cur.Y.X+cur.Y.Y, 0, cur.X);
        else Push(a, cur.Y.X-(a-cur.Y.Y), cur.X);
    }
    cout << -1;
}