#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;


ll arr[100001], dp[100001]={};
// dp[i] = max(0, dp[i-d]~dp[i-1])+arr[i]
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    ll ans=-1e18;
    deque<pair<ll, ll>> dq;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        while (!dq.empty() && dq.front().Y < i-d) dq.pop_front();
        if (!dq.empty()) dp[i] = max((ll)0, dq.front().X)+arr[i];
        else dp[i] = arr[i];
        ans = max(ans, dp[i]);
        while (!dq.empty() && dq.back().X < dp[i]) dq.pop_back();
        dq.push_back(make_pair(dp[i], i));
    }
    cout << ans;
}