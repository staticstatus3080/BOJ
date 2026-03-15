#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (m==1||n==1) {
        cout<<1;
        return 0;
    }
    if (n>=3) {
        if (m>=7) cout<<m-2;
        else {
            if (m<=3) cout<<m;
            else cout<<4;
        }
        return 0;
    }
    if (m<=2) cout<<1;
    else if (m<=4) cout<<2;
    else if (m<=6) cout<<3;
    else cout << 4;
}