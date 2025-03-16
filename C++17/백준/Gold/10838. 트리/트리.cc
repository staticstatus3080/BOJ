#include <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;

int p[100001]={}, pcolor[100001]={};
unordered_set<int> s;
int findR(int a, int b) {
    bool vis[100001]={};
    while (1) {
        if (p[a]!=-1) {
            if (vis[a]) return a;
            vis[a] = true;
            a = p[a];
        }
        if (p[b]!=-1) {
            if (vis[b]) return b;
            vis[b] = true;
            b = p[b];
        }
        if (a==0 && b==0) return 0;
    }
}

void color(int a, int b, int c) {
    while (a!=b) {
        pcolor[a] = c;
        a = p[a];
    }
}

void count(int a, int b) {
    while (a!=b) {
        s.insert(pcolor[a]);
        a = p[a];
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    p[0] = -1;
    int n, k, a, b, c, r, d;
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        cin >> r;
        if (r==1) {
            cin >> a >> b >> c;
            d = findR(a, b);
            color(a, d, c);
            color(b, d, c);
        }
        if (r==2) {
            cin >> a >> b;
            p[a]=b;
        }
        if (r==3) {
            cin >> a >> b;
            d = findR(a, b);
            count(a, d);
            count(b, d);
            cout << s.size() << '\n';
            s.clear();
        }
    }
}