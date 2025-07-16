#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i&1) cout << i/2+1 << ' ';
        else cout << n-(i-1)/2 << ' ';
    }
} 