#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int cnt[4000001]={};
bool np[4000001]={};
vector<int> p;

void fact(int k, int add) {
    for (auto cur : p) {
        int tmp = k;
        while (tmp>0) {
            cnt[cur] += (tmp/cur) * add;
            tmp /= cur;
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n, r, m;
    cin >> n >> r >> m;
    np[1]=1;
    for (int i=2; i<=4000000; i++) {
        if (np[i]) continue;
        p.push_back(i);
        for (ll j=(ll)i*i; j<=4000000; j+=i) {
            np[j]=1;
        }
    }
    fact(n, 1); fact(n-r, -1); fact(r, -1);
    ll ans = 1;
    for (auto cur : p) {
        for (int i=0; i<cnt[cur]; i++) {
            ans *= cur;
            ans %= m;
        }
    }
    cout << ans;
}