#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int k=0, z=s.find('0');
    if (z==-1) {
        cout << -1;
        return 0;
    }
    s.erase(z, 1);
    int len = s.length();
    for (int i=0; i<len; i++) {
        k += s[i]-'0';
    }
    if (k%3==0) {
        sort(s.begin(), s.end(), greater<char>());
        cout << s+'0';
        return 0;
    }
    cout << -1;
}