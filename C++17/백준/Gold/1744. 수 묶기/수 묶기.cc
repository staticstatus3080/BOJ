#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

vector<int> v;
bool vis[51]={};
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    // 음수:음수,0으로 묶어야 이득
    // 0 : 음수로 묶어야 이득
    // 1 : 안묶어야 이득
    // 2 이상:2 이상과 묶어야 이득
    int ans=0;
    for (int i=0; i<n-1; i+=2) {
        if (v[i]<=0 && v[i+1]<=0) {
            ans += v[i]*v[i+1];
            vis[i]=vis[i+1]=1;
        }
        else break;
    }
    for (int i=n-1; i>0; i-=2) {
        if (v[i]>1 && v[i-1]>1) {
            ans += v[i]*v[i-1];
            vis[i]=vis[i-1]=1;
        }
        else break;
    }
    for (int i=0; i<n; i++) {
        if (!vis[i]) ans += v[i];
    }
    cout << ans;
}