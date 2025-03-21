#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
// 재풀이 (공식 활용)
bool check[1000001]={};
vector<ll> primes;

void PrimeSieve() {
    check[1] = check[0] = true;
    for (ll i=2; i<=1000000; i++) {
        if (check[i]) continue;
        primes.push_back(i);
        for (ll j=i*i; j<=1000000; j+=i) {
            check[j] = true;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll origin = n;
    PrimeSieve();
    bool exist=true;
    set<ll> s;
    while (exist) {
        exist = false;
        for (auto p : primes) {
            if (n%p==0) {
                exist = true;
                n/=p;
                s.insert(p);
                break;
            }
        }
        if (n==1) break;
    }
    if (n!=1) s.insert(n);
    n = origin;
    // 인덱스 조회를 위해 vector로 옮김
    vector<ll> v;
    for (ll cur : s) v.push_back(cur);
    ll siz = s.size();
    ll ans=n;
    for (int i=0; i<siz; i++) {
        ans /= v[i];
        ans *= (v[i]-1);
    }
    cout << ans;
}