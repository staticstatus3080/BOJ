#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

map<ll,ll> m;
ll arr[1000001], sum[1000001]={};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n,k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c=='O') arr[i]=-1;
        else arr[i]=k;
    }
    ll ans=0;
    m[0]=0;
    for (int i=1; i<=n; i++) {
        sum[i] = sum[i-1]+arr[i];
        if (sum[i]!=0 && m[sum[i]]==0) m[sum[i]]=i;
        else ans = max(ans,i-m[sum[i]]);
    }
    cout << ans;
}   