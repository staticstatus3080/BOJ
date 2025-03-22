#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    int ans=0;
    for (int i=1; i<=n; i++) {
        int tmp=i;
        while (tmp>0) {
            if (tmp%10==d) ans++;
            tmp /= 10;
        }
    }
    cout << ans;
}