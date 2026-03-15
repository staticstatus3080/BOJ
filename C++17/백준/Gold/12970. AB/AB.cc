#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int arr[100]={};
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, k, t=-1;
    cin >> n >> k;
    if (k==0) {
        for (int i=0; i<n; i++) cout << 'B';
        return 0;
    }
    for (int i=1; i*2<=n; i++) {
        if (i*i<=k && (i+1)*(i+1)>k) {
            t = i;
            break;
        }
    }
    if (t==-1) {
        cout << -1;
        return 0;
    }
    int rem = k-t*t, add=0;
    for (int i=t; i>=1; i--) {
        arr[i] = rem/i;
        rem -= i*arr[i];
        add += arr[i];
    }
    if (t*2+add>n) {
        cout << -1;
        return 0;
    }
    arr[0] = n-(t*2+add);
    arr[t] += t;
    for (int i=0; i<=t; i++) {
        while (arr[i]--)cout << 'B';
        if (i!=t) cout << 'A';
    }
}