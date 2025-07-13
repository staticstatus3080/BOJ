#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

vector<ll> v;
ll dp[101], arr[101], pre[101];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n, m;
    cin >> m >> n;
    for (ll i=0; i<=n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    } 
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
    }
    memset(pre, -1, sizeof(pre));
    for (ll i=0; i<=n; i++) {
        dp[i]=1e11;
        ll sum=0;
        for (ll j=i; j>=0; j--) {
            sum += v[j];
            if (sum>m) break;
            if (j==0) {dp[i]=arr[i]; pre[i]=-1;}
            else if (dp[i]>dp[j-1]+arr[i]){
                dp[i] = dp[j-1]+arr[i];
                pre[i] = j-1;
            } 
        }
    }
    cout << dp[n] << '\n';
    ll tmp=n;
    vector<ll> ans;
    while (pre[tmp]!=-1) {
        ans.push_back(pre[tmp]);
        tmp = pre[tmp];
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur+1 << ' ';
    }
}