#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

bool vis[502]={};
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    int rem=n;
    vector<int> ans;
    int last = n-m+1;
    while (k>0 && rem>=k) {
        for (int i=last; i<last+m; i++) ans.push_back(i);
        rem -= m;
        k--;
        if (k>0 && rem>0 && rem>=k && rem-m<k-1) {
            int a = rem-k+1;
            for (int i=last-a; i<last; i++) ans.push_back(i);
            for (int i=last-a-1; i>=1; i--) ans.push_back(i);
            k=0;
            break;
        }
        last = last-m;
    }
    if (ans.size()==n && k==0) {
        for (auto cur : ans) cout << cur << ' ';
    }
    else cout << -1;
}