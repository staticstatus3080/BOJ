#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

ll arr[51][51], ans[51][51]={};
ll n, m;
void mul() {
    ll tmp[51][51]={};
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                tmp[i][j] += arr[i][k]*arr[k][j];
                tmp[i][j] %= MOD;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void Solve() {
    while (m>0) {
        if (m%2==1) {
            ll tmp[51][51]={};
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    for (int k=1; k<=n; k++) {
                        tmp[i][j] += ans[i][k]*arr[k][j];
                        tmp[i][j] %= MOD;
                    }
                }
            }
            for (int i=1;i<=n; i++) for (int j=1; j<=n; j++) ans[i][j]=tmp[i][j];
        } 
        m/=2;
        mul();
    }
    cout << ans[1][1];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a,b;
        cin >>a >> b;
        arr[a][b]++;
        arr[b][a]++;
    }
    cin >> m;
    for (int i=1; i<=n; i++) ans[i][i]=1;
    Solve();
}   