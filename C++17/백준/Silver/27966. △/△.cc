#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    cout << (n-1)*(n-1) << '\n';
    for (int i=2; i<=n; i++) {
        cout << 1 << ' ' << i << '\n';
    }
}