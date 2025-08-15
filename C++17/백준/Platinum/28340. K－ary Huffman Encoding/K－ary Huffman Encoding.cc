#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (ll i=0; i<n; i++) {
            ll a;
            cin >> a;
            pq.push(a);
        }
        ll ans=0;
        int test = n%(k-1);
        if (test==0) test += k-1;
        int non=0;
        if (test>1) for (int i=0; i<test; i++) {
            non += pq.top();
            pq.pop();
        }
        if (test>1) pq.push(non);
        ans+=non;
        while (pq.size()>1) {
            ll tmp=0;
            for (ll i=0; i<k; i++) {
                tmp += pq.top();
                pq.pop();
                if(pq.empty()) break;
            }
            ans += tmp;
            pq.push(tmp);
        }
        cout << ans << '\n';
    }
}   
