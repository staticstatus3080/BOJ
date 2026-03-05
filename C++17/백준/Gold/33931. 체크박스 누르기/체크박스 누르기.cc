#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;


int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (n>=m) {cout << m; return 0;}
    bool tmp=0;
    while (n<m) {
        m -= n;
        tmp=!tmp;
    }
    if (!tmp) cout << m;
    else cout << n-m;
}